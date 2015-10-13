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
#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

template<typename T>
class Node { 

	template<typename T> friend class LinearList;
	template<typename T> friend class Iterator;
	
     public:
		Node();
		Node(T data);

	private:
		T data;
		Node<T>* next;	    
};

template<typename T>
Node<T>::Node(){
   next = NULL;
}

template<typename T>
Node<T>::Node(T data){
   this->data = data;
   this->next = NULL;
}

#endif