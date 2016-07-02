#include "../Tree.h"
#include <iostream>
#include <vector>

using namespace std;

//          5
//        3   7
//      1  4 6 4 

void populateInOrder(Node *head, vector<int> &inOrderTraversal);
bool validBST(Node *head);
bool validBSTTopDown(Node *head, int minimum, int maximum); 

int main() {
	vector<int> treeValues; 
	treeValues.push_back(5); 
	treeValues.push_back(3); 
	treeValues.push_back(7);
	treeValues.push_back(1); 
	treeValues.push_back(4); 
	treeValues.push_back(6); 


 
	Tree firstTree(treeValues); 
	vector<int> inOrderTraversal; 

	if(validBST(firstTree.get_head())) {
		cout << "Valid BST." << endl;
	} else {
		cout << "Invalid BST." << endl;
	} 

	if(validBSTTopDown(firstTree.get_head(), -1, -1)) {
		cout << "Valid BST." << endl;
	} else {
		cout << "Invalid BST." << endl;
	}
}

void populateInOrder(Node *head, vector<int> &inOrderTraversal) {
	if(head == nullptr) {
		return; 
	}

	populateInOrder(head->left, inOrderTraversal); 
	inOrderTraversal.push_back(head->value); 
	populateInOrder(head->right, inOrderTraversal); 
}

bool validBST(Node *head) {
	vector<int> inOrderTraversal; 
	populateInOrder(head, inOrderTraversal);

	for(int i = 0; i < inOrderTraversal.size()-1; i++) {
		if(inOrderTraversal[i] > inOrderTraversal[i+1]) {
			return false; 
		}
	}
	return true; 
}

bool validBSTTopDown(Node *head, int minimum, int maximum) {
	if(head == nullptr) {
		return true; 
	}

	if((minimum != -1 && head->value < minimum) || (maximum != -1 && head->value > maximum)) {
		return false;
	} 

	return validBSTTopDown(head->left, minimum, head->value) 
		&& validBSTTopDown(head->right, head->value, maximum); 
}