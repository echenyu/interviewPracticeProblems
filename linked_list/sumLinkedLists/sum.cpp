#include <iostream>
#include "../Node.h"

using namespace std;

//8 -> 3
//3 -> 4
//Implement a function that adds together 2 linked lists. 
//TODO: Do the recursive solution & when the list is forwards not backwards. 
Node *sum_linked_lists(Node *head1, Node *head2);
Node *sum_linked_listsRecursive(Node *head, Node *head2, int carry); 
int determineCarry(bool &carry, int &sum);

int main() {
	Node *node1 = new Node(8, 0); 
	Node *node11 = new Node(7, node1); 
	Node *node12 = new Node(9, node11); 

	Node *node2 = new Node(5, 0); 
	Node *node21 = new Node(8, node2); 
	Node *node22 = new Node(6, node21); 

	Node *result = sum_linked_lists(node22, node12); 
	while(result != 0) {
		std::cout << result->value << " ";
		result = result->next; 
	}
	std::cout << std::endl;
}

Node *sum_linked_lists(Node *head1, Node *head2) {
	Node *prevNode = 0;
	Node *sumNode = new Node; 
	Node *head = sumNode; 
	bool carry = false; 

	while(head1 != 0 || head2 != 0) {
		int sum = 0; 

		if(head1) {
			sum += head1->value; 
			head1 = head1->next; 
		}
		if(head2) {
			sum += head2->value; 
			head2 = head2->next; 
		}

		sum = determineCarry(carry, sum); 
		sumNode->value = sum;

		if(prevNode != 0) {
			prevNode->next = sumNode; 
		}
		
		prevNode = sumNode; 
		sumNode = new Node; 
	}

	if(carry) {
		sumNode->value = 1; 
		prevNode->next = sumNode; 
	}

	return head; 
}

Node *sum_linked_listsRecursive(Node *head, Node *head2, int carry) {
	return 0; 
}

int determineCarry(bool &carry, int &sum) {
	if(carry) {
		sum++; 
		carry = false; 
	}
	if(sum >= 10) {
		carry = true; 
		sum = sum % 10; 
	}

	return sum; 
}