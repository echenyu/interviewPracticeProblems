#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &intVector, int left, int right);
int middleOfThreeIndex(int i, int j, int k, vector<int> &intVector);
int partition(int partitionIndex, vector<int> &intVector, int left, int right);

int main() {
	vector<int> intVector; 
	intVector.push_back(8); 
	intVector.push_back(4);
	intVector.push_back(3);
	intVector.push_back(6);   
	intVector.push_back(9); 
	intVector.push_back(3);
	intVector.push_back(10);  
	quickSort(intVector, 0, intVector.size() - 1); 
	for(int i = 0; i < intVector.size(); i++) {
		cout << intVector[i] << " ";
	}
}

void quickSort(vector<int> &intVector, int left, int right) {
	int nextIndex = partition(left, intVector, left, right);

	if(left < nextIndex - 1) {
		quickSort(intVector, left, nextIndex - 1);
	}
	if(nextIndex < right) {
		quickSort(intVector, nextIndex, right); 
	}
}

int middleOfThreeIndex(int i, int j, int k, vector<int> &intVector) {
	if(intVector[i] > intVector[j]) {
		if(intVector[j] > intVector[k]) {
			return j;
		} else if(intVector[i] > intVector[k]) {
			return k;
		} else {
			return i; 
		}
	} else {
		if(intVector[i] > intVector[k]) {
			return i;
		} else if(intVector[j] > intVector[k]) {
			return k;
		} else {
			return j; 
		}
	}
}
//1 12 5 26 7 14 3 1 2  Chooses 2 as the partition. Left = 0. Right = 8
//First pass, swap 2 and 12. Set left = 2, right = 7
//Break out of loop. 1 2 5 26 7 14 3 7 12
int partition(int partitionIndex, vector<int> &intVector, int left, int right) {
	int pivot = intVector[partitionIndex];
	while(left <= right) {
		while(intVector[left] < pivot) {
  			left++; 
		}
		while(intVector[right] > pivot) {
			right--; 
		}
		if(left <= right) {
			swap(intVector[left], intVector[right]); 
			left++; right--; 
		}
	}
	return left; 
}