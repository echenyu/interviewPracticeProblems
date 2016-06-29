#include <vector>
#include <deque>
#include <queue>
#include "Node.h"

class Tree {
public:
	Tree() :head(0) {}
	Tree(std::vector<int> treeValues_in) {
		createTree(treeValues_in);
	}

	void push(int value);	

	//Function to check if the tree is a mirror image. 
	bool checkIfMirrored(); 
	bool checkIfMirroredRecursive(); 

	//Functions to print traversal of the tree
	void printPreOrder(); 
	void printPostOrder(); 
	void printInOrder(); 
	void printLevelOrder(); 

	// TO DO: 
	void printTree(); 	
private:
	Node *head; 
	Node *nodeToInsertAt; 
	std::deque<Node *> insertedNodes; 
	void createTree(std::vector<int> treeValues_in);
	void printTreeHelper(Node *currentNode, int indent);
	bool checkLevel(std::vector<Node *> &children, std::queue<Node *> &levelNodes); 
	bool isPalindrome(std::vector<Node *> &children); 
	bool checkIfMirroredRecursive_helper(Node *left, Node *right); 
	void printPreHelper(Node *current); 
	void printPostHelper(Node *current); 
	void printInOrderHelper(Node *current); 
};