//A set of linked lists for each level of a tree
//
#include <iostream>
#include <vector>
#include <queue>
#include "../Tree.h"

using namespace std;

vector<Node *> createListsForDepth(Node *head);

int main() {
	vector<int> treeValues; 
	
	treeValues.push_back(1); 
	treeValues.push_back(2); 
	treeValues.push_back(2);
	treeValues.push_back(3); 
	treeValues.push_back(3); 
	treeValues.push_back(3); 
	treeValues.push_back(3); 
	treeValues.push_back(7); 


	Tree firstTree(treeValues); 
	vector<Node *> levels = createListsForDepth(firstTree.get_head()); 
	for(int i = 0; i < levels.size(); i++) {
		Node *head = levels[i]; 
		cout << "Level " << i << ":"; 
		while(head != nullptr) {
			cout << head->value << " "; 
			head = head->left; 
		}
		cout << endl;
	}
}

vector<Node *> createListsForDepth(Node *head) {
	queue<Node *> currentLevel; 
	vector<Node *> parentNodes; 
	vector<Node *> nodesAtLevel; 

	currentLevel.push(head); 

	Node *current = new Node; 
	Node *levelHead = current; 
	Node *prev = nullptr; 
	while(!currentLevel.empty()) {
		if(currentLevel.front() == nullptr) {
			currentLevel.pop(); 
			continue; 
		}

		current->value = currentLevel.front()->value; 
		if(prev) {
			prev->left = current; 
		}
		parentNodes.push_back(currentLevel.front()); 
		currentLevel.pop(); 
		prev = current; 
		current = new Node; 
		
		if(currentLevel.empty()) {
			for(int i = 0; i < parentNodes.size(); i++) {
				currentLevel.push(parentNodes[i]->left); 
				currentLevel.push(parentNodes[i]->right); 
			}
			parentNodes.clear(); 
			nodesAtLevel.push_back(levelHead); 
			prev = nullptr; 
			levelHead = current; 
		}
	}
	if(parentNodes.size() != 0) {
		nodesAtLevel.push_back(parentNodes[0]); 
	}

	return nodesAtLevel; 
}