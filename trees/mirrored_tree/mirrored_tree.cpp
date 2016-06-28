#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

int main () {
	vector<int> treeValues; 
	for(int i = 0; i < 1048575; i++) {
		treeValues.push_back(1); 
	}
	treeValues.push_back(1); 
	treeValues.push_back(2); 
	treeValues.push_back(2);
	treeValues.push_back(3); 
	treeValues.push_back(4); 
	treeValues.push_back(4); 
	treeValues.push_back(3); 


	Tree firstTree(treeValues); 

	if(firstTree.checkIfMirrored()) {
		cout << "Tree is a mirror image." << endl;
	} else {
		cout << "Tree is not a mirror image." << endl;
	}

	if(firstTree.checkIfMirroredRecursive()) {
		cout << "Tree is a mirror image." << endl;
	} else {
		cout << "Tree is not a mirror image." << endl;
	}
}

