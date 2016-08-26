#include <iostream>
#include "../Node.h"

using namespace std; 

//1 -> 3 -> 7 -> 10
//Empty List
//1 
//1 4 1 3 asks for the fifth element? 
int kthToLast(int kth, Node *head);
int findNumberOfNodes(Node *head);
int nodeValueToReturn(int indexToStopOn, Node *head);
int kthToLastDoubleTraversal(int kth, Node *head);

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


	std::cout << kthToLast(1, newNode) << " is first to last." << std::endl; 
	std::cout << kthToLast(4, newNode) << " is the 4th to last." << std::endl;
	std::cout << kthToLast(5, newNode) << " is invalid" << std::endl;
	std::cout << kthToLast(10, newNode4->next) << " is invalid\n" << std::endl;

	// Using two nodes to traverse the linked list
	std::cout << kthToLastDoubleTraversal(1, newNode) << std::endl;
	std::cout << kthToLastDoubleTraversal(5, newNode) << std::endl;
}

// Find the count first, and then figure out how to traverse the linked list
int kthToLast(int kth, Node *head) {
	if(head == 0) {
		return -1; 
	}
	int countOfNodes = findNumberOfNodes(head); 
	if(kth > countOfNodes) {
		return -1; 
	}
	int indexToStopOn = countOfNodes-kth; 

	return nodeValueToReturn(indexToStopOn, head); 
}

// Have two nodes to traverse the list
int kthToLastDoubleTraversal(int kth, Node *head) {
	if(head == 0) {
		return -1; 
	}

	Node *returnedNode = head; 
	Node *traversalNode = head; 
	int traversalCounter = 0; 

	while(traversalNode->next != 0) {
		if(traversalCounter >= kth-1) {
			returnedNode = returnedNode->next; 
		}
		traversalCounter++; 
		traversalNode = traversalNode->next; 
	}
	if(kth > traversalCounter) {
		return -1; 
	}

	return returnedNode->value; 
}

int findNumberOfNodes(Node *head) {
	int countOfNodes = 0; 
	Node *current = head; 
	while(current != 0) {
		countOfNodes++; 
		current = current->next; 
	}
	return countOfNodes; 
}

int nodeValueToReturn(int indexToStopOn, Node *head) {
	int countOfNodes = 0; 
	Node *returnedNode = head; 
	while(countOfNodes < indexToStopOn) {
		returnedNode = returnedNode->next; 
		countOfNodes++; 
	}
	return returnedNode->value; 
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode(0); 
        ListNode *slow = start, *fast = start;
        start->next = head;
        
        for(int i = 0; i <= n; i++) {
            fast = fast->next; 
        }
        
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return start->next; 
    }
};

