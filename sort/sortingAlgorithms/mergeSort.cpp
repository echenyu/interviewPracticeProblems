#include <iostream>
#include <vector>

using namespace std; 

vector<int> createSortedVector(vector<int> first, vector<int> second) {
	int firstIndexer = 0; 
	int secondIndexer = 0; 
	vector<int> newVector; 
	while(firstIndexer != first.size() || secondIndexer != second.size()) {
		if(firstIndexer == first.size()) {
			newVector.push_back(second[secondIndexer]); 
			secondIndexer++; 
			continue; 
		}
		if(secondIndexer == second.size()) {
			newVector.push_back(first[firstIndexer]); 
			firstIndexer++; 
			continue; 
		}

		if(first[firstIndexer] < second[secondIndexer]) {
			newVector.push_back(first[firstIndexer]); 
			firstIndexer++; 
		} else {
			newVector.push_back(second[secondIndexer]); 
			secondIndexer++; 
		}
	}

	return newVector; 
}

// 1 2 3 4 5
vector<int> mergeSortHelper(vector<int> &values, int left, int right) {
	if(left == right) {
		vector<int> newVector; 
		newVector.push_back(values[left]); 
		return newVector; 
	}

	int mid = (left + right) / 2; 
	vector<int> first = mergeSortHelper(values, left, mid); 
	vector<int> second = mergeSortHelper(values, mid+1, right); 

	return createSortedVector(first, second); 
}

vector<int> mergeSort(vector<int> &values) {
	return mergeSortHelper(values, 0, values.size() - 1); 
}
