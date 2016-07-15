#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void createPeaksAndValleysSorted(vector<int> &listOfInts);
void createPeaksAndValleys(vector<int> &listOfInts);

int main() {
	vector<int> randomVector; 
	randomVector.push_back(1); 
	randomVector.push_back(1); 
	randomVector.push_back(2); 
	randomVector.push_back(3);
	randomVector.push_back(5);
	randomVector.push_back(8); 

 
	vector<int> randomVector2 = randomVector; 

	createPeaksAndValleysSorted(randomVector); 
	for(int i = 0; i < randomVector.size(); i++) {
		cout << randomVector[i] << " ";
	}
	cout << endl;

	createPeaksAndValleys(randomVector2); 
	for(int i = 0; i < randomVector2.size(); i++) {
		cout << randomVector2[i] << " ";
	}
	cout << endl;
}

void createPeaksAndValleysSorted(vector<int> &listOfInts) {
	sort(listOfInts.begin(), listOfInts.end());

	for(int i = 1; i < listOfInts.size(); i+=2) {
		swap(listOfInts[i], listOfInts[i-1]); 
	}
}

void createPeaksAndValleys(vector<int> &listOfInts) {
	bool isHill = true; 

	for(int i = 0; i < listOfInts.size()-1; i++) {
		if((isHill && listOfInts[i] < listOfInts[i+1]) || (!isHill && listOfInts[i] > listOfInts[i+1])) {	
			swap(listOfInts[i], listOfInts[i+1]); 
		}
		isHill = !isHill; 
	}
}