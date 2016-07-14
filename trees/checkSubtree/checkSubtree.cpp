#include <iostream>
#include "../Tree.h"

using namespace std;

int main() {

}

bool checkSubtree(Node *root, Node *subTreeNode) {
	if(root == nullptr) {
		return false; 
	}
	if(root == subTreeNode) {
		bool isSubtree = matchingTrees(root, subTreeNode); 
		if(isSubtree) {
			return true; 
		}
	}
	return checkSubtree(root->left, subTreeNode) || checkSubtree(root->right, subTreeNode); 
}

bool matchingTrees(Node *root, Node *subTreeNode) {
	if(root == subTreeNode) {
		if(root == nullptr) {
			return true; 
		}
		return matchingTrees(root->left, subTreeNode->left) && matchingTrees(root->right, subTreeNode->right); 
	} else {
		return false; 
	}
}
