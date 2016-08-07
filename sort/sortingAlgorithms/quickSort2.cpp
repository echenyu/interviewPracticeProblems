#include <iostream>
#include <vector>

using namespace std;

void quickSortHelper(vector<int> &unsorted, int left, int right);
int partition(vector<int> &unsorted, int left, int right, int pivot);

void quickSort(vector<int> &unsorted) {
	quickSortHelper(unsorted, 0, unsorted.size() - 1);
}

int main() {
	vector<int> tempVector; 
	tempVector.push_back(8); 
	tempVector.push_back(4);
	tempVector.push_back(3);
	tempVector.push_back(6);   
	tempVector.push_back(9); 
	tempVector.push_back(3);
	tempVector.push_back(7);  
 
	quickSort(tempVector); 
	for(int i = 0; i < tempVector.size(); i++) {
		cout << tempVector[i] << " ";
	}
	cout << endl;
}

// 4 1 8 9 6
// 4 1 6 9 8 <-- return the index of 9

void quickSortHelper(vector<int> &unsorted, int left, int right) {
	cout << "Sorting: ";
	for(int i = left; i <= right; i++) {
		cout << unsorted[i] << " ";
	}


	int nextIndex = partition(unsorted, left, right, left); 
	cout << "The next index is " << nextIndex << " with: " << left << " and " << right << endl;
	if(left < nextIndex - 1) 	
		quickSortHelper(unsorted, left, nextIndex - 1); 

	if(right > nextIndex)
		quickSortHelper(unsorted, nextIndex+1, right); 
}

int partition(vector<int> &unsorted, int left, int right, int pivot) {
	int pivotValue = unsorted[pivot]; 

	while(left <= right) {
		while(unsorted[left] <= pivotValue) {
			left++; 
		}
		while(unsorted[right] > pivotValue) {
			right--; 
		}
		if(left >= right) {
			break; 
		}
		swap(unsorted[left], unsorted[right]); 	
	}
	swap(unsorted[left], unsorted[pivot]); 	

	return left; 
}