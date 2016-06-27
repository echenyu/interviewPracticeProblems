#include "IntList.h"
#include <cassert>
#include <iostream>

// Constructor, destructor, copy constructor, assignment operator
IntList::IntList() : head(0), tail(0) { } 
IntList::~IntList() { removeAll(); }
IntList::IntList(const IntList &other) :head(0), tail(0) { copyAll(other); }
IntList &IntList::operator=(const IntList &other) {
	if(this == &other) return *this; 
	removeAll();
	copyAll(other); 
	return *this; 
}

// Public Methods
bool IntList::isEmpty() const {
	if(head == 0) {
	return true;
	}
	return false;
}

void IntList::insertFront(int i) {
	Node *newNode = new Node; 
	newNode->next = head; 
	newNode->val = i; 
	if(isEmpty()) {
		head = tail = newNode; 
	} else {
		head = newNode; 
	}
}

void IntList::insertBack(int i) {
	Node *newNode = new Node; 
	newNode->next = 0; 
	newNode->val = i; 
	if(isEmpty()) {
		head = tail = newNode; 
	} else {
		tail->next = newNode; 
		tail = newNode; 
	}
}

int IntList::removeFront() {
	assert(!isEmpty()); 
	Node *current = head; 
	int value = head->val;
	head = current->next; 
	delete current; current = 0;
	return value; 
}

//Private Methods
void IntList::removeAll() {
	while(!isEmpty()) {
		removeFront(); 
	}
}

void IntList::copyAll(const IntList &other) {
	Node *current = other.head; 
	while(current) {
		int val = current->val; 
		insertBack(val); 
		current = current->next; 
	}
}