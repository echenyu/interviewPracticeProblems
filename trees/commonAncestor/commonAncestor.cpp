#include "../Tree.h"
#include <iostream>
#include <unordered_set>

//			5
//		3		7
//	1	  4	  6		8

using namespace std;

Node *findCommonAncestorSpace(Node *firstNode, Node *secondNode);
Node *findCommonAncestor(Node *root, Node *firstNode, Node *secondNode);
Node *findCommonAncestorFromRoot(Node *root, Node *firstNode, Node *secondNode); 
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);
bool covers(Node *root, Node *nodeToFind);

int main () {
	vector<int> treeValues; 
	treeValues.push_back(5); 
	treeValues.push_back(3); 
	treeValues.push_back(7);
	treeValues.push_back(1); 
	treeValues.push_back(4); 
	treeValues.push_back(6); 
	treeValues.push_back(8); 

	Tree treeToTest(treeValues); 
	Node *root = treeToTest.get_head(); 
	Node *firstNode = root->left; 
	Node *secondNode = root->left->right; 
	cout << findCommonAncestor(root, firstNode, secondNode)->value << " is ancestor" << endl;
	cout << lowestCommonAncestor(root, firstNode, secondNode)->value << " is faster" << endl;
}

//If there is a parent pointer
Node *findCommonAncestorSpace(Node *firstNode, Node *secondNode) {
	// if(firstNode == nullptr || secondNode == nullptr) {
	// 	nullptr; 
	// }

	// unordered_set<Node *> firstNodePath; 

	// while(firstNode != nullptr) {
	// 	firstNodePath.insert(firstNode); 
	// 	firstNode = firstNode->parent; 
	// }

	// while(secondNode != nullptr) {
	// 	if(firstNodePath.find(secondNode) != firstNodePath.end()) {
	// 		return secondNode; 
	// 	}
	// 	secondNode = secondNode->parent; 
	// }

	return nullptr; 
}

//Check a subtree (either left or right) to see if both first and second node are covered
// 	If yes, 
//		Check the next left subtree
// If no, 
//		If both on right side
//			Check for the right subtree
//		else
//			return the current node
//
Node *findCommonAncestor(Node *root, Node *firstNode, Node *secondNode) {
	if(!covers(root, firstNode) || !covers(root, secondNode)) {
		return nullptr; 
	}
	return findCommonAncestorFromRoot(root, firstNode, secondNode); 
}

Node *findCommonAncestorFromRoot(Node *root, Node *firstNode, Node *secondNode) {
	if(firstNode == nullptr || secondNode == nullptr) {
		return nullptr;  
	} else if(root == firstNode || root == secondNode) {
		return root;
	}

	bool firstNodeOnLeft = false; 
	bool secondNodeOnLeft = false; 
	if(covers(root->left, firstNode)) firstNodeOnLeft = true;
	if(covers(root->left, secondNode)) secondNodeOnLeft = true; 

	if(firstNodeOnLeft != secondNodeOnLeft) return root; 

	if(firstNodeOnLeft == false) {
		return findCommonAncestorFromRoot(root->right, firstNode, secondNode); 
	}

	return findCommonAncestorFromRoot(root->left, firstNode, secondNode);
}

bool covers(Node *root, Node *nodeToFind) {
	if(!root) return false;
	if(root == nodeToFind) return true; 

	return covers(root->left, nodeToFind) || covers(root->right, nodeToFind); 
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(!root || root == p || root == q) {
        return root; 
    }
    
	Node *left = lowestCommonAncestor(root->left, p, q); 
	Node *right = lowestCommonAncestor(root->right, p, q); 
	
	if(!left) return right;
	if(right) return root; 
	return left; 
}