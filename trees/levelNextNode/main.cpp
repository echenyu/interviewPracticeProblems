#include <iostream>
#include "nextNode.cpp"

using namespace std;

// {2,1,3,0,7,9,1,2,#,1,0,#,#,8,8,#,#,#,#,7}
int main() {
	Node *n1 = new Node();
	Node *n2 = new Node();
	Node *n3 = new Node();
	Node *n4 =new Node();
	Node *n5 = new Node();
	Node *n6 =new Node();
	Node *n7 =new Node();
	Node *n8 =new Node();
	Node *n9 = new Node();
	Node *n10 =new Node(); 
	Node *n11 =new Node(); 
	Node *n12 =new Node();
	Node *n13 = new Node(); 
	n1->val = 2;
	n2->val = 1;
	n3->val = 3; 
	n4->val = 0;
	n5->val = 7;
	n6->val = 9; 
	n7->val = 1;
	n8->val = 2;
	n9->val = 1;
	n10->val = 0;
	n11->val = 8;
	n12->val = 8;
	n13->val = 7;
	n1->left = n2; 
	n1->right = n3;
	n2->left = n4;
	n2->right = n5; 
	n3->left = n6;
	n3->right = n7; 
	n4->left = n8;
	n5->left = n9;
	n5->right = n10;
	n7->left = n11;
	n7->right = n12; 
	n10->left = n13; 

	connect(n1); 

}