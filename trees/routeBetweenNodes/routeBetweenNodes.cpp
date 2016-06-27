// Given a directed graph - figure out if there's a path between 
// two nodes. 

#include <iostream>
#include "Node.h"
#include <deque>
#include <vector>

using namespace std;

bool isThereAPath(Node *node1, Node *node2);
bool checkNodes(deque<Node *> &bfs, Node *toCompare);

int main() {
	Node *child1 = new Node; child1->value = 1; 
	Node *child2 = new Node; child2->value = 2; 
	Node *child3 = new Node; child3->value = 3; 
	Node *childOfChild1 = new Node; childOfChild1->value = 4; 
	Node *head = new Node; head->value = 0; 

	vector<Node *> headChildren; 
	vector<Node *> childrenOfChild1; 
	vector<Node *> cyclic; 

	headChildren.push_back(child1); 
	headChildren.push_back(child2); 
	headChildren.push_back(child3); 
	childrenOfChild1.push_back(childOfChild1); 
	cyclic.push_back(head); 
	
	head->children = headChildren; 
	child1->children = childrenOfChild1; 
	child2->children = cyclic; 
	
	if(isThereAPath(head, childOfChild1)) {
		cout << "found a path." << endl;
	} else {
		cout << "no path." << endl;
	}
}

bool isThereAPath(Node *node1, Node *node2) {
	deque<Node *> bfs; 
	bfs.push_front(node1); 
	if(checkNodes(bfs, node2)) {
		return true;
	}

	bfs.push_front(node2); 
	return checkNodes(bfs, node1); 
}

bool checkNodes(deque<Node *> &bfs, Node *toCompare) {
	while(!bfs.empty()) {
		Node *current = bfs.front(); 
		bfs.pop_front(); 

		if(!current->visited) {
			if(current == toCompare) {
				return true;
			}
			current->visited = true; 
			for(int i = 0; i < current->children.size(); i++) {
				bfs.push_back(current->children[i]); 
			}
		}
	}
	return false; 
}