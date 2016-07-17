#include <iostream>
#include "bubbleSort.cpp"
#include "selectionSort.cpp"
#include <vector>

using namespace std;

void printVector(string type, vector<int> &sortedVector); 
vector<int> createUnsortedVector(); 

int main() {
	vector<int> unsortedVector = createUnsortedVector(); 
	printVector("Original", unsortedVector); 
	selectionSort(unsortedVector); 
	printVector("Selection", unsortedVector); 
	cout << "\n"; 

	unsortedVector = createUnsortedVector();
	printVector("Original", unsortedVector); 
	bubbleSort(unsortedVector); 
	printVector("Bubble", unsortedVector); 
	cout << "\n"; 
}

void printVector(string type, vector<int> &sortedVector) {
	if(type == "Selection") {
		cout << "Selection Sort: ";
	} else if(type == "Bubble") {
		cout << "Bubble Sort: ";
	} else if(type == "Original") {
		cout << "Unsorted: ";
	} else {
		cout << "Unrecognized sort: ";
	}
			
	for(int i = 0; i < sortedVector.size(); i++) {
		cout << sortedVector[i] << " ";
	}
	cout << endl;
}

vector<int> createUnsortedVector() {
	vector<int> tempVector; 

	tempVector.push_back(8); 
	tempVector.push_back(4);
	tempVector.push_back(3);
	tempVector.push_back(6);   
	tempVector.push_back(9); 
	tempVector.push_back(3);
	tempVector.push_back(10);  

	return tempVector; 
}