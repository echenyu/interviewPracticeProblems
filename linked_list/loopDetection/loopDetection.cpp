#include <iostream>
#include <unordered_set>
#include "../Node.h"

using namespace std;

Node *headOfLoopHash(Node *root); 
Node *headOfLoop(Node *root);

//1 3 3 1 5 1  and last one points to the 3 
int main() {
	Node *newNode = new Node(1, nullptr);
	Node *newNode2 = new Node(5, newNode); 
	Node *newNode3 = new Node(1, newNode2); 
	Node *newNode4 = new Node(3, newNode3);
	Node *newNode5 = new Node(3, newNode4); 
	Node *newNode6 = new Node(1, newNode5); 
	newNode->next = newNode5; 
	cout << headOfLoop(newNode6)->value << " is the loop head" << endl; 
}

Node *headOfLoopHash(Node *root) {
	//If there isn't a loop, we will return nullptr	
	unordered_set<Node *> nodes; 
	while(root->next != nullptr) {
		if(nodes.find(root) != nodes.end()) {
			return root; 
		}
		nodes.insert(root); 
		root = root->next; 
	}

	return nullptr; 
}

//Fast runner slow runner solution for looped circular list. 
Node *headOfLoop(Node *root) {
	Node *slowRunner = root;
	Node *fastRunner = root; 

	while(fastRunner != nullptr && fastRunner->next != nullptr) {
		slowRunner = slowRunner->next; 
		fastRunner = fastRunner->next->next; 
		if(slowRunner == fastRunner) {
			break; 
		}
	}

	if(fastRunner == nullptr || fastRunner->next == nullptr) {
		return nullptr; 
	}

	slowRunner = root;
	while(slowRunner != fastRunner) {
		slowRunner = slowRunner->next;
		fastRunner = fastRunner->next; 
	}

	return slowRunner; 
}