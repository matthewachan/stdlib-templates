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
#ifndef LINEARLIST_H
#define LINEARLIST_H

#include "Node.h"
#include "Iterator.h"
#include<iostream>
using namespace std;

/********************************* CLASS DECLARATION ******************************************/
template<typename T>
class LinearList {

	template<typename T> friend ostream& operator<<(ostream& os, const LinearList<T>& l);

	public:
		LinearList();											// Constructor
		~LinearList();											// Destructor
		LinearList(const LinearList<T>& l);						// Copy Constructor
		LinearList<T>& operator=(const LinearList<T>& l);		// Assignment operator overload
		Iterator<T> begin()const;								// Returns an Iterator at the first Node		
		Iterator<T> end()const;									// Returns an Iterator at the last NULL Node
		Iterator<T> search(T data)const;						// Returns an Iterator at the Node containing the given data
		Iterator<T> previous(Iterator<T>& current);				// Returns an Iterator at the previous Node
		void insert(Iterator<T>& before, T data);				// Inserts a Node with given data right before the given Iterator's position
		void remove(Iterator<T>& current);						// Removes the Node at the given Iterator's position
		bool isEmpty()const;									// Determines whether the LinearList has any Nodes
		void empty();											// Empties out all Nodes from the LinearList
		void reverse();											// Reverses the order of the LinearList
		
	private:
		Node<T>* head;
};

/********************************* CLASS DEFINITIONS ******************************************/
template<typename T>
void LinearList<T>::reverse() {
	LinearList<T> temp;
	for (Iterator<T> i = begin(); !(i == end()); i.next()){
		temp.insert(temp.begin(), i.get());
	}
	*this = temp;
	temp.empty();
}

template<typename T>
LinearList<T>::LinearList(){
	head = NULL;
}

template<typename T>
LinearList<T>::~LinearList(){
	empty();
}

template<typename T>
LinearList<T>::LinearList(const LinearList<T>& l){
	head = NULL;
	for (Iterator<T> i = l.begin(); !(i == l.end()); i.next()){
		insert(end(), i.get());
	}
}

template<typename T>
LinearList<T>& LinearList<T>::operator=(const LinearList<T>& l){
	if (this != &l){
		empty();
		for (Iterator<T> i = l.begin(); !(i == l.end()); i.next()){
			insert(end(), i.get());
		}
	}
	return (*this);
}

template<typename T>
Iterator<T> LinearList<T>::begin()const{
	Iterator<T> i;
	i.position = head;
	i.container = this;
	return i;
}

template<typename T>
Iterator<T> LinearList<T>::end()const{
	Iterator<T> i;
	i.position = NULL;
	i.container = this;
	return i;
}

template<typename T>
Iterator<T> LinearList<T>::search(T data)const {
	for (Iterator<T> i = begin(); !(i == end()); i.next()){
		if (i.get() == data){
			return i;
		}
	}
	return end();
}

template<typename T>
Iterator<T> LinearList<T>::previous(Iterator<T>& current){
	for (Iterator<T> i = begin(); !(i == end()); i.next()) {
		if (i.position->next == current.position) {
			return i;
		}
	}
	return end();
}

// Inserts a Node with the given data before the Node at the iterator before
template<typename T>
void LinearList<T>::insert(Iterator<T>& before, T data){
	Node<T>* temp = new Node<T>(data);

	if (before == begin()){
		// insert at beginning of the list
		temp->next = head;
		head = temp;
	}
	else {
		Iterator<T> current = previous(before);
		temp->next = current.position->next;
		current.position->next = temp;
	}
}

template<typename T>
void LinearList<T>::remove(Iterator<T>& current){
	if (current == end())  return;
	else if (current == begin()){
		head = head->next;
		delete current.position;
	}
	else{
		Iterator<T> prev = previous(current);
		prev.position->next = current.position->next;
		delete current.position;
	}
}

template<typename T>
bool LinearList<T>::isEmpty()const{
	return (begin() == end());
}

template<typename T>
void LinearList<T>::empty(){
	while (!isEmpty()){
		remove(begin());
	}
}

template<typename T>
ostream& operator<<(ostream& os, const LinearList<T>& l){
	for (Iterator<T> i = l.begin(); !(i == l.end()); i.next()){
		os << i.get() << " ";
	}
	os << endl;
	return os;
}

#endif