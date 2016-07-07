#include <iostream>

using namespace std;

int main() {

}
//		  13	
//     7
//   5    10 
// 1  6  8  

//Test Cases: 
// Current Node -> Right child node
// Current Node -> Root Node
// Current Node -> Smallest node in the tree
// Current Node -> Largest node in the tree
// 

// Current Node = left child with 2 children - 5 node leftmost node of the right subtree
// Current Node = left child with no children - 1 node parent node
// Current = left child with left child - 1 node parent node
// Current = left child with right child. - leftmost node of the right subtree
// Current = right child with 2 children - 10 node leftmost node of the right subtree
// Current = right child with no children - 12 node - return nullptr
// Current = right child with left child. - parent's parent node, parent of parent nonexistent = nullptr
// Current = right child with right child. leftmost node of the right subtree

// Current Node 
Node *findNextNode(Node *current) {
	Node *nextNode; 
	if (current->parent == nullptr) {
		if(current->parent->right == nullptr) {
			nextNode = nullptr; 
		} else {
			nextNode = findNextNode_helper(current->parent->right);  
		}
	} else {
		if(current == current->parent->left) {
			if(current->right != nullptr) {
				nextNode = findNextNode_helper(current->right); 
			} else {
				nextNode = current->parent; 
			}
		} else {
			if(current->right != nullptr) {
				nextNode = findNextNode_helper(current->right); 
			} else if (current->right == nullptr && current->left == nullptr) {
				nextNode = nullptr;  
			} else {
				if(current->parent->parent != nullptr) {
					nextNode = current->parent->parent; 
				} else {
					nextNode = nullptr; 
				}
			}
		}
	}

	return nextNode; 
}

Node *findNextNode_helper(Node *rightChild) {
	if(rightChild->left == nullptr && rightChild->right == nullptr) {
		return rightChild; 
	}
	return findNextNode_helper(rightChild->left); 
}