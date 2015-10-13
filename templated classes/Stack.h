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
#ifndef STACK_H
#define STACK_H

#include "LinearList.h"
#include"Iterator.h"

/********************************* CLASS DECLARATION ******************************************/
template<typename T>
class Stack {
	
	template<typename T> friend ostream& operator<< (ostream& out, const Stack<T>& s);
	
	public:
			Stack();									// Constructor
			~Stack();									// Destructor
			Stack(const Stack<T>& s);					// Copy Constructor
			Stack<T>& operator=(const Stack<T>& s);		// Assignment operator overload
			void push(T data);							// Adds a Nodes with the given data to the end of the Stack
			void pop();									// Removes the last Node from the Stack
			T top() const;								// Returns the value of the last Node in the Stack
			bool isEmpty() const;						// Determines whether the Stack contains any Nodes
			void empty();								// Removes all Nodes from the Stack
			unsigned int getSize() const;				// Returns the number of Nodes in the Stack
	
	private:
			unsigned int size;
			LinearList<T> list;
};

/********************************* CLASS DEFINITIONS ******************************************/
template<typename T>
ostream& operator<<(ostream& out, const Stack<T>& s) {
	for (Iterator<T> i = s.list.begin(); !(i == s.list.end()); i.next()) {
		out << i.get() << " ";
	}
	out << endl;
	return out;
}

template<typename T>
Stack<T>::Stack() {
	size = 0;
}

template<typename T>
Stack<T>::~Stack() {
	empty();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& s) {
	for (Iterator<T> i = list.begin(); !(i == list.end()); i.next()) {
		list.insert(i.end(), i.get());
	}
	size = s.size;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
	if (this != &s) {
		empty();
		for (Iterator<T> i = list.begin(); !(i == list.end()); i.next()) {
			list.insert(i.end(), i.get());
		}
		size = s.size;
	}
	return *this;
}

template<typename T>
unsigned int Stack<T>::getSize() const{
	return size;
}

template<typename T>
T Stack<T>::top() const {
	T retval;
	for (Iterator<T> i = list.begin(); !(i == list.end()); i.next()) {
		retval = i.get();
	}
	return retval;
}

template<typename T>
void Stack<T>::push(T data) {
	list.insert(list.end(), data);
	size++;
}

template<typename T>
void Stack<T>::pop() {
	list.remove(list.previous(list.end()));
	size--;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return (list.begin() == list.end());
}

template<typename T>
void Stack<T>::empty() {
	while (!isEmpty()) {
		pop();
	}
	size = 0;
}

#endif