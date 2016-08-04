#include <iostream>
#include <vector>

using namespace std;

int findElementIndex(int valueToFind, int left, int right, vector<int> &rotatedVector);

int main() {
	vector<int> rotatedVector;
	rotatedVector.push_back(15); 
	rotatedVector.push_back(16); 
	rotatedVector.push_back(20); 
	rotatedVector.push_back(20); 
	rotatedVector.push_back(20); 
	rotatedVector.push_back(1); 
	rotatedVector.push_back(3); 
	rotatedVector.push_back(4); 
	rotatedVector.push_back(5); 
	rotatedVector.push_back(7); 
	rotatedVector.push_back(10); 
	rotatedVector.push_back(14); 
	cout << findElementIndex(20, 0, rotatedVector.size()-1, rotatedVector) << " is the index" << endl;
}

int findElementIndex(int valueToFind, int left, int right, vector<int> &rotatedVector) {
	int middleElement = (left + right) / 2; 
	if(rotatedVector[middleElement] > valueToFind) {
		if(valueToFind < rotatedVector[left]) {
			return findElementIndex(valueToFind, middleElement+1, right, rotatedVector); 
		} else {
			return findElementIndex(valueToFind, left, middleElement-1, rotatedVector);
		}
	} else if(rotatedVector[middleElement] < valueToFind) {
		if(valueToFind > rotatedVector[right]) {
			return findElementIndex(valueToFind, left, middleElement-1, rotatedVector); 
		} else {
			return findElementIndex(valueToFind, middleElement+1, right, rotatedVector); 
		}
	} 
	
	return middleElement; 
}