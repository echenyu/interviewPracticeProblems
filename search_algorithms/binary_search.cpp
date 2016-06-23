#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<int> searchVector, int value);

int main() {
	vector<int> newVector; 
	for(int i = 0; i < 10; i++) {
		newVector.push_back(i); 
	}

	int value = 10; 
	if(binary_search(newVector, value)) {
		cout << "I found the value." << endl;
	} else {
		cout << "Tough luck." << endl;
	}
}

bool binary_search(vector<int> searchVector, int value) {
	int left = 0; 
	int right = searchVector.size() - 1; 

	while(right >= left) {
		int middle = (left + right) / 2; 
		if(value == searchVector[middle]) {
			return true; 
		} else if (value > searchVector[middle]) {
			left = middle + 1; 
		} else {
			right = middle - 1; 
		}
	}

	return false; 
}