#include <iostream>
#include <vector>
#include "../Node.h"
#include <deque>

using namespace std;

Node *createMinimalTree(vector<int> &sortedVector, int leftIndex, int rightIndex);
//Answer: 2 (root)
//      1  3
//     0    4 
//
// 2^n elements inside of a vector
// 2*2^(n-1) + 2^2*2^(n-2)... + 2^(n-1) 2^1 + 2^n * 2^0 + 0
// log2(2^n) * 2^n
// f * log2(f)

// 2log2(f) 

int main() {
	//Root node = ~middle
	vector<int> sortedVector; 
	for(int i = 0; i < 5; i++) {
		sortedVector.push_back(i); 
	}

	createMinimalTree(sortedVector, 0, sortedVector.size() -1); 
}

//0 1 2 3 4 -> 0, 4  ---> headOfTree->value = 2
	//headOfTree->left 0 1 -> 0 1 headOfTree->left->value = 0
	//headOfTree->right 3 4 -> 3 4 headOfTree->right->value = 3 
//      2
//    0   3
//  0  1 3  4 
// Figure out better ways to step through the problem. 
// Linear approach to the communication when it might not actually
// come linearly. 
Node *createMinimalTree(vector<int> &sortedVector, int leftIndex, int rightIndex) {
	if(rightIndex < leftIndex) {
		return nullptr; 
	}

	Node *headOfTree = new Node; 
	int sum = leftIndex + rightIndex; 
	int middleIndex; 
	(sum % 2) ? middleIndex = sum/2 + 1 : middleIndex = sum / 2;
	headOfTree->value = sortedVector[middleIndex]; 

	headOfTree->left = createMinimalTree(sortedVector, leftIndex, middleIndex-1);
	headOfTree->right = createMinimalTree(sortedVector, middleIndex+1, rightIndex);
	return headOfTree; 
}

