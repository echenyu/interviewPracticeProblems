#include "../Node.h"
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
	Node *newNode = new Node(1, nullptr);
	Node *newNode2 = new Node(5, newNode); 
	Node *newNode3 = new Node(1, newNode2); 
	Node *newNode4 = new Node(3, newNode3);
	Node *newNode5 = new Node(3, newNode4); 
	Node *newNode6 = new Node(1, newNode5); 
	Node *head = newNode6; 
	while(head != nullptr) {
		cout << head->value << " "; 
		head = head->next; 
	}
	cout << endl;

	removeDuplicates(newNode6); 
	head = newNode6;
	while(head != nullptr) {
		cout << head->value << " "; 
		head = head->next; 
	}
	cout << endl;
}

//1 3 3 1 5 1
void removeDuplicates(Node *head){
	if (head == nullptr){
		return;
	} 

	while (head != nullptr){
		int object_val = head->value;
		Node *prev = head;
		Node *next = head->next;
		while (next != nullptr)
		{
			if (object_val == next->value){
				prev->next = next->next;
			} else {
				prev = prev->next; 
			}
			next = next->next;
		}
		head = head->next; 
	}
}

void removeDuplicatesHash(Node *head) {
	unordered_map<int, Node *> nodeMap;
	Node *current = head; 
	Node *prev = nullptr;
	while(current != nullptr) {
		if(nodeMap.find(current->value) != nodeMap.end()) {
			prev->next = current->next; 
		} else {
			nodeMap[current->value] = current;
			prev = current; 
		}
		current = current->next;
	}
}