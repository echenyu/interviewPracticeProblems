#include <iostream>
#include <vector>

using namespace std;

// 3 1 8 
// 3 1 
// 3 
void mergeSort(vector<int> &unsortedVector);
vector<int> combineLeftRight(vector<int> &left, vector<int> &right);
vector<int> mergeSortHelper(vector<int> &unsortedVector, int left, int right);

int main() {
	vector<int> tempVector; 
	tempVector.push_back(8); 
	tempVector.push_back(4);
	tempVector.push_back(3);
	tempVector.push_back(6);   
	tempVector.push_back(9); 
	tempVector.push_back(3);
	tempVector.push_back(10);  
	mergeSort(tempVector); 
	for(int i = 0; i < tempVector.size(); i++) {
		cout << tempVector[i] << " ";
	}
	cout << endl;
}

void mergeSort(vector<int> &unsortedVector) {
	unsortedVector = mergeSortHelper(unsortedVector, 0, unsortedVector.size() - 1); 
}

vector<int> mergeSortHelper(vector<int> &unsortedVector, int left, int right) {
	if(left == right) {
		vector<int> newVector;
		newVector.push_back(unsortedVector[left]); 
		return newVector; 
	}

	int middle = (left + right) / 2; 
	vector<int> leftSide = mergeSortHelper(unsortedVector, left, middle);
	vector<int> rightSide = mergeSortHelper(unsortedVector, middle + 1, right); 
	
	return combineLeftRight(leftSide, rightSide); 
}

vector<int> combineLeftRight(vector<int> &left, vector<int> &right) {
	bool leftEmpty = false; 
	int leftIndexer = 0, rightIndexer = 0; 
	vector<int> combinedVector;

	while(leftIndexer != (left.size()) && rightIndexer != (right.size())) {
		if(left[leftIndexer] < right[rightIndexer]) {
			combinedVector.push_back(left[leftIndexer]); 
			leftIndexer++; 
		} else {
			combinedVector.push_back(right[rightIndexer]);
			rightIndexer++; 
		}
	}

	(leftIndexer == left.size()) ? leftEmpty = true : leftEmpty = false; 

	leftEmpty ? combinedVector.insert(combinedVector.end(), right.begin() + rightIndexer, right.end()) : combinedVector.insert(combinedVector.end(), left.begin() + leftIndexer, left.end()); 

	return combinedVector; 
}