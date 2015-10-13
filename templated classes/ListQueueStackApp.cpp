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
#include "LinearList.h"
#include "Queue.h"
#include "Stack.h"
#include<iostream>
#include <string>
using namespace std;

// Returns a given number n with a base b
unsigned int changeBase(unsigned int n, unsigned int b) {
	Stack<int> s;
	// Push the each base to the nth power (starting at 0) onto the Stack until the base is larger than the given unsigned integer
	for (int exponent = 0; exponent <= UINT_MAX; exponent++) {
		if (pow(b, exponent) > n) {
			break;
		}
		s.push(pow(b, exponent));
	}
	unsigned int retval = 0;
	// Add each base digit to the return value
	for (int i = s.getSize() - 1; i >= 0; i--) {
		retval += (int)(n / s.top()) * pow(10,i);
		n = n % s.top();
		s.pop();
	}
	return retval;
}

// Determines whether a given phrase is a palindrome (spelled the same backwards and forwards)
bool isPalindrome(string phrase) {
	// Create a stack and queue
	Stack<char> s;
	Queue<char> q;
	// Push each char in the string onto the stack and queue
	for (int i = 0; i < phrase.length(); i++) {
		s.push(phrase[i]);
		q.push(phrase[i]);
	}
	// Check that the first element in the Queue is equal to the first element in the Stack
	while (!s.isEmpty() && !q.isEmpty()) {
		if (s.top() != q.front()) return false;
		// Remove the last element from the Stack
		s.pop();
		// Remove the first element from the Queue
		q.pop();
	}
	return true;
}

int main(){
	cout << "Base Converter" << endl << "Enter a non-negative integer: ";
	// Prompt the user for an integer value
	int n;
	cin >> n;
	// Print out their number with bases from 2 to 9
	for (int base = 2; base <= 9; base++)
		cout << "[" << changeBase(n, base) << "]_" << base << endl;
	cout << endl;
	cout << "Palindrome Tester" << endl << "Enter a phrase: ";
	// Prompt the user from a string value
	string phrase;
	cin >> phrase;
	// Inform the user whether their string is a palindrome or not
	if (isPalindrome(phrase))
		cout << phrase << " is a Palindrome." << endl;
	else
		cout << phrase << " is not a Palindrome." << endl;
	return 0;
}