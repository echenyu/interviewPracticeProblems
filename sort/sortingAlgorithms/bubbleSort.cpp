#include <iostream>
#include <algorithm>
#include <vector>

//8 4 3 3 9 3 10 
//First Pass: Swap 8 and 4
//Second Pass: 8 & 3
//Third Pass: 8 & 3
void bubbleSort(std::vector<int> &unsortedVector) {

	bool isSorted = false; 
	while(!isSorted) {
		isSorted = true; 
		for(int j = 0; j < unsortedVector.size()-1; j++) {
			if(unsortedVector[j] > unsortedVector[j+1]) {
				std::swap(unsortedVector[j], unsortedVector[j+1]); 
				isSorted = false; 
			}
		}
	}
}