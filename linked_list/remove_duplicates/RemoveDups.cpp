#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//First implementation that doesn't use a buffer, but has O(n^2) time. 
//Goes through every Node and compares to every other node
void removeDuplicates(Node *head);

// Hash table solution. O(n) time but also O(n) space. 
void removeDuplicatesHash(Node *head);

int main()
{	
	Node *newNode = new Node(2, NULL);
	Node *newNode2 = new Node(1, newNode); 
	Node *newNode3 = new Node(2, newNode2); 
	Node *head = newNode3; 
	while(head != NULL) {
		cout << head->value << " "; 
		head = head->next; 
	}
	cout << endl;
	removeDuplicatesHash(newNode3); 
	head = newNode3; 
	while(head != NULL) {
		cout << head->value << " "; 
		head = head->next; 
	}
	cout << endl;
}

void removeDuplicates(Node *head){
	if (head == NULL){
		return;
	}
	while (head!= NULL){
		int object_val = head->value;
		Node *prev = head;
		Node *next = head->next;
		while (next != NULL)
		{
			if (object_val == next->value){
				prev->next = next->next;
			}
			else{
				prev = next;
			}
			next = next->next;
		}
	removeDuplicates(head->next);
	return;
	}
}

void removeDuplicatesHash(Node *head) {
	unordered_map<int, Node *> nodeMap;
	Node *current = head; 
	Node *prev = NULL;
	while(current != NULL) {
		if(nodeMap[current->value]) {
			prev->next = current->next; 
		} else {
			nodeMap[current->value] = current;
			prev = current; 
		}
		current = current->next;
	}
}