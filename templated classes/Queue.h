/*
Matthew Chan					    PIC 10B Intermediate Programming
ID: 604178275          		  		Winter 2015
Email: matthew.a.chan@gmail.com		Assignment #6
Section: 2B
Honesty Pledge:

I, Matthew Chan, pledge that this is my own independent
work,which conforms to the guidelines of academic honesty as
described in the course syllabus.

List of known bugs: None.
*/
#ifndef QUEUE_H
#define	QUEUE_H

#include "LinearList.h"
#include "Iterator.h"

/********************************* CLASS DECLARATION ******************************************/
template<typename T>
class Queue {
	template<typename T> friend ostream& operator<<(ostream& out, const Queue<T>& q);
	public:
		Queue();									// Constructor
		~Queue();									// Destructor
		Queue(const Queue<T>& q);					// Copy Constructor
		Queue<T>& operator=(const Queue<T>& q);		// Assignment operator overload
		void push(T data);							// Adds a Node with the given data at the end of the Queue
		void pop();									// Removes the first Node from the Queue
		T front() const;							// Returns the value of the first Node in the Queue
		bool isEmpty() const;						// Determines whether the Queue has any Nodes
		void empty();								// Removes all Nodes from the Queue
		unsigned int getSize() const;				// Returns the number of Nodes the Queue has

	private:
		unsigned int size;
		LinearList<T> list;
};

/********************************* CLASS DEFINITIONS ******************************************/
template<typename T>
Queue<T>::Queue() {
	size = 0;
}

template<typename T>
ostream& operator<<(ostream& out, const Queue<T>& q) {
	for (Iterator<T> i = q.list.begin(); !(i == q.list.end()); i.next()) {
		out << i.get() << " ";
	}
	out << endl;
	return out;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& q) {
	list.head = NULL;
	for (Iterator<T> i = q.list.begin(); !(i == q.list.end()); i.next()) {
		list.insert(list.end(), i.get());
	}
	size = q.size;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
	if (this != &q) {
		empty();
		for (Iterator<T> i = q.list.begin(); !(i == q.list.end()); i.next()) {
			list.insert(list.end(), i.get());
		}
		size = q.size;
	}
	return *this;
}

template<typename T>
void Queue<T>::push(T data) {
	list.insert(list.end(), data);
	size++;
}

template<typename T>
T Queue<T>::front() const {
	return list.begin().get();
}

template<typename T>
void Queue<T>::pop() {
	list.remove(list.begin());
	size--;
}

template<typename T>
Queue<T>::~Queue() {
	empty();
}

template<typename T>
bool Queue<T>::isEmpty() const {
	return (list.begin() == list.end());
}

template<typename T>
void Queue<T>::empty() {
	 while (!isEmpty()) 
		 this->pop();
	 size = 0;
}

template<typename T>
unsigned int Queue<T>::getSize() const {
	return size;
}

#endif