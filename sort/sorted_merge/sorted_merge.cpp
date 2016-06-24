#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b);

int main() {
	cout << "hello." << endl;
	vector<int> newVector;
	newVector.push_back(1);
	newVector.push_back(5);
	newVector.push_back(7);
	newVector.push_back(9);
	newVector.push_back(50); 
	vector<int> newVector2;
	newVector2.push_back(2);
	newVector2.push_back(4);
	newVector2.push_back(11);
	newVector2.push_back(23);
	newVector2.push_back(51);

	vector<int> merged = merge(newVector, newVector2); 
	for(int i = 0; i < merged.size(); i++) {
		cout << merged[i] << " ";
	}
	cout << endl;
}

vector<int> merge(vector<int> &a, vector<int> &b) {
	int a_index = 0; 
	int b_index = 0; 
	vector<int> temp_vector;

	int count = 0; 
	while (count < a.size() + b.size()) {
		if(a_index == a.size()-1 && b_index != b.size()-1) {
			temp_vector.push_back(b[b_index]);
			b_index++; 
		} else if (b_index == b.size()-1 && a_index != a.size()-1) {
			temp_vector.push_back(a[a_index]); 
			a_index++; 
		}
		if(a[a_index] < b[b_index]) {
			temp_vector.push_back(a[a_index]); 
			a_index++; 
		} else {
			temp_vector.push_back(b[b_index]); 
			b_index++; 
		}
		count++; 
	}
	cout << b[b_index] << endl;
	cout << a_index << " and " << b_index << endl;
	return temp_vector; 
}