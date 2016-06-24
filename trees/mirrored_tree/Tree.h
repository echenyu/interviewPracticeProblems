#include <vector>
#include <deque>
#include "Node.h"

class Tree {
public:
	Tree() :head(0) {}
	Tree(std::vector<int> treeValues_in) {
		createTree(treeValues_in);
	}

	void push(int value);	
	void printLevelOrder(); 
	bool checkIfMirrored(); 

	// TO DO: 
	void printTree(); 
	void printPreOrder(); 
	void printPostOrder(); 
	void printInOrder(); 

private:
	Node *head; 
	Node *nodeToInsertAt; 
	std::deque<Node *> insertedNodes; 
	void createTree(std::vector<int> treeValues_in);
	void printTreeHelper(Node *currentNode, int indent);
};