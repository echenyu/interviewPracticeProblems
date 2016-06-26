#include <iostream>
#include "../Node.h"
#include <cassert>

//10 --> 7 --> 3 --> 1
//No good way to delete the node if it's the last node. 
//Current solution is to set the node's value to -1. 
//TODO - figure out a way to set the node to null. 
//Would work if you passed a double pointer, or had
//a doubly linked list. 
void deleteNodeInMiddle(Node *&current);

int main() {
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

	Node *current = newNode; 
	while(current != 0) {
		std::cout << current->value << "-->"; 
		current = current->next; 
	}
	std::cout << "nil node" << std::endl;

	deleteNodeInMiddle(newNode3); 

	current = newNode;
	while(current != 0) {
		std::cout << current->value << "-->"; 
		current = current->next; 
	}
	std::cout << "nil node" << std::endl;

	deleteNodeInMiddle(newNode3);

	current = newNode;
	while(current != 0x0) {
		std::cout << current->value << "-->"; 
		current = current->next;
	}
	std::cout << "nil node" << std::endl;
}

void deleteNodeInMiddle(Node *&current) {
	if(current->next == 0) {
		current->value = -1; 
	} else {
		Node *tempNode = current->next; 
		current->value = tempNode->value; 
		current->next = tempNode->next; 
		delete tempNode; tempNode = 0; 
	}
	return; 
}