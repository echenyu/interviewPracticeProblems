#include <iostream>
#include "../Node.h"
#include <stack>

// How to check if a linked list is a palindrome or not. 
//Two solutions - recursive or iterative. Iterative is easy - just use a stack
//Recursive was hard, but my implementation was actually pretty close to the book
using namespace std;

bool checkPalindrome(Node *head);
bool checkPalindromeRecursive(Node *head);

int main() {
	Node *node1 = new Node(8, 0); 
	Node *node11 = new Node(1, node1); 
	Node *node12 = new Node(7, node11); 
	Node *node13 = new Node(7, node12); 
	Node *node14 = new Node(1, node13); 
	Node *node15 = new Node(8, node14); 
	if(checkPalindromeRecursive(node15)) {
		cout << "we good." << endl;
	} else {
		cout << ":(" << endl;
	}
}

bool checkPalindrome(Node *head) {
	Node *current = head; 
	stack<int> reverseOrder; 
	while(current != 0) {
		reverseOrder.push(current->value); 
		current = current->next;
	}

	current = head; 
	while(current != 0) {
		if(current->value != reverseOrder.top()) {
			return false; 
		}
		reverseOrder.pop(); 
		current = current->next; 
	}

	return true; 
}

bool compareNodes(Node *one, Node *&two) {
	if(one->value != two->value) {
		return false; 
	}
	return true; 
}

bool checkPalindromeRecursive_helper(Node *head, int length, Node *&nodeToCompare) {
	if(length == 0) {
		nodeToCompare = head->next; 
		return compareNodes(head, nodeToCompare); 
	} else if(length == 1) {
		nodeToCompare = head->next; 
		return true; 
	}

	if(checkPalindromeRecursive_helper(head->next, length-2, nodeToCompare)) {
		nodeToCompare = nodeToCompare->next; 
		return compareNodes(head, nodeToCompare); 
	} else {
		return false; 
	}

	return true; 
}

bool checkPalindromeRecursive(Node *head) {
	Node *current = head; 
	Node *nodeToCompare = 0; 
	int length = 0;  
	while(current != 0) {
		length++; 
		current = current->next;
	}
	if(length == 0 || length == 1) {
		return true; 
	}
	return checkPalindromeRecursive_helper(head, length-2, nodeToCompare); 
}