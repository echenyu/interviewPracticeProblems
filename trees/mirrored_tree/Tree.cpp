#include "Tree.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <ctime> 

/******************************* PUBLIC METHODS *******************************/
/*****************************************************************************/
void Tree::push(int value) {
	Node *newNode = new Node(0, 0, value);

	if(!head) {
		head = newNode; 
		nodeToInsertAt = head; 
	} else {
		if(nodeToInsertAt->left == 0) {
			nodeToInsertAt->left = newNode;
		} else if(nodeToInsertAt->right == 0) {
			nodeToInsertAt->right = newNode; 
			nodeToInsertAt = insertedNodes[0]; 
			insertedNodes.pop_front(); 
		}
		insertedNodes.push_back(newNode); 
	}
}

//Multiple ways to implement. By allocating a queue, we can do this is O(n) time and space. 
void Tree::printLevelOrder() {
	std::queue<Node *> queueToPrint; 
	queueToPrint.push(head); 

	while(!queueToPrint.empty()) {
		Node *current = queueToPrint.front(); 
		std::cout << current->value << " ";
		queueToPrint.pop(); 
		
		if(current->left != NULL) {
			queueToPrint.push(current->left); 
		} 
		if(current->right != NULL) {
			queueToPrint.push(current->right); 
		}
	}
	std::cout << "is the level-order traversal" << std::endl;
	return; 
}

void Tree::printTree() {
	printTreeHelper(head, 0); 
	return;
}

void Tree::printPreOrder() {

}

void Tree::printPostOrder() {

}

void Tree::printInOrder() {
	
}

bool Tree::checkIfMirrored() {
	int start_s = clock(); 
	std::queue<Node *> levelNodes;
	std::vector<Node *> children; 
	levelNodes.push(head); 

	while(!levelNodes.empty()) {
		Node *currentNode = levelNodes.front(); 
		levelNodes.pop(); 
		children.push_back(currentNode); 

		if(levelNodes.empty()) {
			// Check level will see if the children form a palindrome
			// Null nodes will be represented as 0's. Children will be emptied
			// at the end of this function and inserted into level Nodes. 
			if(!checkLevel(children, levelNodes)) {
				int stop_s = clock(); 
				std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << " execution time for iterative answer" << std::endl;
				return false; 
			}
		}
	}
	int stop_s = clock(); 
	std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << " execution time for iterative answer" << std::endl;

	return true; 
}

bool Tree::checkIfMirroredRecursive() {
	if(!head) return false; 
	int start_s = clock(); 

	bool x = checkIfMirroredRecursive_helper(head->left, head->right); 

	int stop_s = clock(); 
	std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << " execution time for recursive answer" << std::endl;
	return x; 
}

/******************************PRIVATE METHODS *******************************/
/*****************************************************************************/
void Tree::createTree(std::vector<int> treeValues_in) {
	if(treeValues_in.size() == 0) {
		return; 
	}
	for(int i = 0; i < treeValues_in.size(); i++) {
		push(treeValues_in[i]); 
	}
	return;
}

void Tree::printTreeHelper(Node *currentNode, int indent = 0) {
	if(currentNode != NULL) {
        if(currentNode->left) printTreeHelper(currentNode->left, indent+4);
        if(currentNode->right) printTreeHelper(currentNode->right, indent+4);
        if (indent) {
        } else {
        	std::cout << "First: " << currentNode->value << std::endl;
        }

        std::cout<< currentNode->value << "\n ";
    }
}

bool Tree::checkLevel(std::vector<Node *> &children, std::queue<Node *> &levelNodes) {
	if(!isPalindrome(children)) {
		return false; 
	} else {
		for(int i = 0; i < children.size(); i++) {
			Node *current = children[i]; 
			if(current == 0) {
				continue; 
			}
			levelNodes.push(current->left); 
			levelNodes.push(current->right); 
		}
		children.clear(); 
	}
	return true; 
}

bool Tree::isPalindrome(std::vector<Node *> &children) {
	if(children.size() == 0) {
		return true; 
	}

	int endIndex = children.size() - 1; 
	int value, value2; 

	for(int i = 0; i < children.size() / 2; i++, endIndex--) {
		children[i] ? value = children[i]->value : value = 0;
		children[endIndex] ? value2 = children[endIndex]->value : value2 = 0;
		if(value != value2) {
			return false; 
		}
	}
	return true; 
}

bool Tree::checkIfMirroredRecursive_helper(Node *left, Node *right) {
	if(left == 0 || right == 0) {
		return (left == right);
	}
	return (left->value == right->value) && checkIfMirroredRecursive_helper(left->left, right->right) 
		&& checkIfMirroredRecursive_helper(left->right, right->left); 
}