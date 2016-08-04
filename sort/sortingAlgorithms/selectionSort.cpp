#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int smallerIndexVal(int indexOne, int indexTwo, vector<int> &unsortedVector);
void swapElements(int indexOne, int indexTwo, vector<int> &unsortedVector); 

void selectionSort(std::vector<int> &unsortedVector) {
	for(int i = 0; i < unsortedVector.size(); i++) {
		int smallestElementIndex = i;
		for(int j = i+1; j < unsortedVector.size(); j++) {
			smallestElementIndex = smallerIndexVal(smallestElementIndex, j, unsortedVector); 
		}
		swapElements(i, smallestElementIndex, unsortedVector); 
	}
}

int smallerIndexVal(int indexOne, int indexTwo, vector<int> &unsortedVector) {
	if(unsortedVector[indexOne] <= unsortedVector[indexTwo]) {
		return indexOne;
	} 
	return indexTwo; 
}

void swapElements(int indexOne, int indexTwo, vector<int> &unsortedVector) {
	if(indexOne != indexTwo) {
		swap(unsortedVector[indexOne], unsortedVector[indexTwo]); 
	}
}