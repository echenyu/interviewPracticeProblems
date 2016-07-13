#include <iostream>
#include <cmath>
#include "../Node.h"

using namespace std; 

//Given 2 singly linked lists.
// 1 3 5 6
// 7 8 1 3 5 6
Node *checkIntersection(Node *firstNode, Node *secondNode);
Node *findLastNode(Node *current, int &lengthToEnd);
Node *findSameIndexNode(Node *current, int length);

int main() {
	//10 7 3 1
	Node *newNode = new Node;
	newNode->value = 10; 
	Node *newNode2 = new Node; 
	newNode2->value = 7; 
	Node *newNode3 = new Node; 
	newNode3->value = 3; 
	Node *newNode4 = new Node; 
	newNode4->value = 1; 
	newNode->next = newNode2; 
	newNode2->next = newNode3; 
	newNode3->next = newNode4; 

	Node *neNode = new Node;
	neNode->value = 10; 
	Node *neNode2 = new Node; 
	neNode2->value = 7; 
	Node *neNode3 = new Node; 
	neNode3->value = 3; 
	Node *neNode4 = new Node; 
	neNode4->value = 1; 
	neNode->next = neNode2; 
	neNode2->next = neNode3; 
	neNode3->next = neNode4; 

	Node *intersectingNode = checkIntersection(newNode, newNode2); 
	if(intersectingNode != nullptr) {
		cout << intersectingNode->value << " is the intersection" << endl;
	} else {
		cout << "No intersection" << endl;
	}
}

Node *checkIntersection(Node *firstNode, Node *secondNode) {
	if(firstNode == nullptr || secondNode == nullptr) {
		return nullptr; 
	}

	int lengthToEndFirst, lengthToEndSecond; 

	Node *lastNodeOfFirst = findLastNode(firstNode, lengthToEndFirst); 
	Node *lastNodeOfSecond = findLastNode(secondNode, lengthToEndSecond); 
	Node *intersectingNode = nullptr; 

	if(lastNodeOfSecond == lastNodeOfFirst) {
		int differenceOfLength = abs(lengthToEndFirst - lengthToEndSecond); 
		if(differenceOfLength != 0) {
			if(lengthToEndFirst > lengthToEndSecond) {
				firstNode = findSameIndexNode(firstNode, differenceOfLength); 
			} else {
				secondNode = findSameIndexNode(secondNode, differenceOfLength); 
			}
		}
		while(firstNode != secondNode) {
			firstNode = firstNode->next;
			secondNode = secondNode->next; 
		}
		intersectingNode = firstNode; 
	} 
	return intersectingNode; 
}

Node *findLastNode(Node *current, int &lengthToEnd) {
	int count = 0; 
	while(current->next != nullptr) {
		current = current->next; 
		count++; 
	}
	lengthToEnd = count; 
	return current; 
}

Node *findSameIndexNode(Node *current, int length) {
	for(int i = 0; i < length; i++) {
		current = current->next; 
	}
	return current; 
}