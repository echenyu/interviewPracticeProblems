#include "Node.h"
#include <cmath>
#include <iostream>

bool isBalanced(Node *root);
int checkHeight(Node *root); 
int max(int one, int two);

int main () {
	Node *leftTree = new Node();
	Node *leftTree2 = new Node(); 
	Node *leftTree3 = new Node(); 
	leftTree->left = leftTree2; 
	leftTree2->left = leftTree3; 

	Node *rightTree = new Node(); 
	Node *rightTree2 = new Node(); 
	rightTree->right = rightTree2; 
	Node *root = new Node(leftTree, rightTree);
	 
	if(isBalanced(root)) {
		std::cout << "We balanced bitches." << std::endl;
	} else {
		std::cout << ":(" << std::endl;
	} 
}

bool isBalanced(Node *root) {
	if(root == NULL) {
		return true; 
	}
	int left = checkHeight(root->left);
	int right = checkHeight(root->right); 
	std::cout << left << " and " << right << std::endl;
	if(abs(left-right) > 1) {
		return false; 
	} else if (left == 0 && right == 0){
		return true; 
	} else {
		return isBalanced(root->left) && isBalanced(root->right); 
	}
}

int checkHeight(Node *root) {
	std::cout << "Height checked" << std::endl;
	
	if(root == NULL) {
		std::cout << "Depth of 0." << std::endl;
		return 0; 
	} else if(root->tree_depth != -1) {
		return root->tree_depth; 
	} else if (root->left == NULL && root->right == NULL) {
		std::cout << "Depth of 1." << std::endl;
		root->tree_depth = 1; 
	} else {
		root->tree_depth = 1 + max(checkHeight(root->left), checkHeight(root->right)); 
	}
	return root->tree_depth; 
}

int max(int one, int two) {
	return (one > two) ? one : two; 
}