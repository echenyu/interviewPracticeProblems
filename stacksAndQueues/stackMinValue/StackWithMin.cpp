#include "StackWithMin.h"
#include <iostream>

using namespace std; 

StackWithMin::StackWithMin() {}

void StackWithMin::pop() {
	if(isEmpty()) {
		return; 
	}

	if(stackVector[stackVector.size() - 1] == minimum()) {
		minVector.resize(minVector.size() - 1); 
	}

	stackVector.resize(stackVector.size() - 1); 
}

void StackWithMin::push(int value) {
	if(isEmpty()) {
		minVector.push_back(value); 
	} else {
		if(value <= minVector[minVector.size() - 1]) {
			minVector.push_back(value); 
		}
	}

	stackVector.push_back(value);
}

int StackWithMin::top() {
	if(isEmpty()) {
		return -1; 
	}
	return stackVector[stackVector.size() - 1]; 
}

bool StackWithMin::isEmpty() {
	if(stackVector.size() == 0) {
		return true;
	}

	return false; 
}

int StackWithMin::minimum() {
	if(isEmpty()) {
		return -1; 
	}
	return minVector[minVector.size() - 1]; 
}