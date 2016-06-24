#include "Tree.h"
#include <iostream>
#include <iomanip>
#include <queue>

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
	printPreHelper(head); 
	std::cout << "is the pre-order traversal" << std::endl;
}

void Tree::printPostOrder() {
	printPostHelper(head); 
	std::cout << "is the post-order traversal" << std::endl;
}

void Tree::printInOrder() {
	printInOrderHelper(head); 
	std::cout << "is the in-order traversal" << std::endl;
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

void Tree::printPreHelper(Node *current) {
	if(current == 0) {
		return; 
	}
	std::cout << current->value << " "; 
	printPreHelper(current->left); 
	printPreHelper(current->right); 
}

void Tree::printPostHelper(Node *current) {
	if(current == 0) {
		return; 
	}
	printPostHelper(current->left); 
	printPostHelper(current->right); 
	std::cout << current->value << " "; 
}

void Tree::printInOrderHelper(Node *current) {
	if(current == 0) {
		return; 
	}
	printInOrderHelper(current->left); 
	std::cout << current->value << " ";
	printInOrderHelper(current->right); 
}