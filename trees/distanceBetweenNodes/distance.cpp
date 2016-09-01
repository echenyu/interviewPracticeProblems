#include <iostream>
#include "../Tree.h"
#include <vector>

using namespace std; 

Node* lowestCommonAncestor(Node* root, Node* p, Node* q);
int distanceBetweenNodes(Node *root, Node *left, Node *right);
int distanceBetweenNodes_helper(Node *ancestor, Node *toFind, int sum);

//			1
//		2		3
//	 4	  5	  6		7
//8
int main () {
	vector<int> treeValues; 
	treeValues.push_back(1); 
	treeValues.push_back(2); 
	treeValues.push_back(3);
	treeValues.push_back(4); 
	treeValues.push_back(5); 
	treeValues.push_back(6); 
	treeValues.push_back(7); 
	treeValues.push_back(8); 

	Tree treeToTest(treeValues); 
	Node *root = treeToTest.get_head(); 
	cout << "Distance (4, 5): " << distanceBetweenNodes(root, root->left->left, root->left->right) << endl;
	cout << "Distance (4, 6): " << distanceBetweenNodes(root, root->left->left, root->right->left) << endl;
	cout << "Distance (3, 4): " << distanceBetweenNodes(root, root->left->left, root->right) << endl;
	cout << "Distance (2, 4): " << distanceBetweenNodes(root, root->left, root->left->left) << endl;
	cout << "Distance (1, 1): " << distanceBetweenNodes(root, root, root) << endl;
}

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

int distanceBetweenNodes(Node *root, Node *left, Node *right) {
	int sum = 0; 
	Node *ancestor = lowestCommonAncestor(root, left, right); 
	int leftLength = distanceBetweenNodes_helper(ancestor, left, sum);
	int rightLength = distanceBetweenNodes_helper(ancestor, right, sum);
	return leftLength + rightLength;  
}

int distanceBetweenNodes_helper(Node *ancestor, Node *toFind, int sum) {
	if(!ancestor) return 0; 
	if(ancestor == toFind) return sum; 

	return max(distanceBetweenNodes_helper(ancestor->left, toFind, sum+1),
				distanceBetweenNodes_helper(ancestor->right, toFind, sum+1));
}