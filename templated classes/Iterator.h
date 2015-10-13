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
#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include<assert.h>
#include<iostream>
using namespace std;

/********************************* CLASS DECLARATION ******************************************/
template<typename T>
class Iterator {
	
	template<typename T> friend class LinearList;
	
	public:
		Iterator();										// Constructor
		void next();									// Moves position pointer to the next Node
		T get() const;									// Returns the value stored at the current Node
		bool operator==(const Iterator<T>& it) const;	// Determines whether two iterators are at the same position
		
	private:
		Node<T>* position;
		const LinearList<T>* container;
};

/********************************* CLASS DEFINITIONS ******************************************/
template<typename T>
Iterator<T>::Iterator(){
	position = NULL;
	container = NULL;
}

template<typename T>
void Iterator<T>::next(){
	assert(position != NULL);
	position = position->next;
}

template<typename T>
T Iterator<T>::get()const{
	assert(position != NULL);
	return position->data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& it)const{
	return position == it.position;
}
#endif