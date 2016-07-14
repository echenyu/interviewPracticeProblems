//A set of linked lists for each level of a tree
//
#include <iostream>
#include <vector>
#include <queue>
#include "../Tree.h"
#include <map>

using namespace std;

vector<Node *> createListsForDepth(Node *head);
vector<Node *> createListsForDepthHash(Node *head);
void createListsForDepthHash_helper(Node *head, map<int, vector<Node *> > &nodesAtLevel, int count); 

//          1
//        2   2
//       3 3 3 3 
//		7

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
	vector<Node *> levels = createListsForDepthHash(firstTree.get_head()); 
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
vector<Node *> createListsForDepthHash(Node *head) {
	map<int, vector<Node *> > nodesAtLevel;
	createListsForDepthHash_helper(head, nodesAtLevel, 1);  
	vector<Node *> nodesAtLevel_vector; 
	map<int, vector<Node *> >::iterator it;

	for(it = nodesAtLevel.begin(); it != nodesAtLevel.end(); it++) {
		vector<Node *> nodes = it->second; 
		Node *prev = nullptr; 
		Node *head = nodes[0]; 
		for(int i = 0; i < nodes.size(); i++) {
			
			Node *current = nodes[i]; 
			current->left = nullptr; 
			if(prev) {
				prev->left = current; 
			}
			prev = current; 
		}
		nodesAtLevel_vector.push_back(head);
	}
	return nodesAtLevel_vector; 
}

void createListsForDepthHash_helper(Node *head, map<int, vector<Node *> > &nodesAtLevel, int count) {
	if(head == nullptr) {
		return; 
	}

	if(nodesAtLevel.find(count) != nodesAtLevel.end()) {
		vector<Node *> currentLevel = nodesAtLevel[count]; 
	} else {
		nodesAtLevel[count] = vector<Node *>(); 
	}

	nodesAtLevel[count].push_back(head); 
	createListsForDepthHash_helper(head->left, nodesAtLevel, count+1); 
	createListsForDepthHash_helper(head->right, nodesAtLevel, count+1); 
}
