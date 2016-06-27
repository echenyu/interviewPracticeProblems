#include <iostream>
#include "../Node.h"

using namespace std;

// 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
// 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
//This problem is to move all nodes around a partition. 
//All nodes greater than the partition must come after all
//nodes less than the partition
void partitionAroundX(Node *head, int value);

int main() {
	Node *node7 = new Node(1, 0); 
	Node *node6 = new Node(2, node7); 
	Node *node5 = new Node(10, node6); 
	Node *node4 = new Node(5, node5); 
	Node *node3 = new Node(8, node4); 
	Node *node2 = new Node(5, node3); 
	Node *node1 = new Node(3, node2); 

	partitionAroundX(node1, 3); 
	Node *current = node1; 
	while(current != 0) {
		cout << current->value << " ";
		current = current->next; 
	}
	cout << endl;
}

void partitionAroundX(Node *head, int value) {
	Node *lessThanPartition = head; 
	Node *partition = head; 
	bool foundPartition = false; 

	while(lessThanPartition != 0) {
		if(!foundPartition) {
			if(partition->value >= value) {
				foundPartition = true; 
			} else {
				partition = partition->next;
			} 
		} 
		if(foundPartition && lessThanPartition->value < value) {
			int tempVal = lessThanPartition->value; 
			lessThanPartition->value = partition->value; 
			partition->value = tempVal; 
			foundPartition = false; 
			partition = partition->next; 
		}
		lessThanPartition = lessThanPartition->next; 
	}
}