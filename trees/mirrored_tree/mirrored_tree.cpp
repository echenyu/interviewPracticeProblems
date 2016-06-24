#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

int main () {
	vector<int> treeValues; 
	for(int i = 0; i < 6; i++) {
		treeValues.push_back(i); 
	}

	Tree firstTree(treeValues); 
	firstTree.printLevelOrder(); 
	firstTree.printPreOrder(); 
	firstTree.printPostOrder(); 
	firstTree.printInOrder(); 
}

