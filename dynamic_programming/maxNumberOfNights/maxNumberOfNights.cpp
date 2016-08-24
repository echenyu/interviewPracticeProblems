#include <iostream>
#include <vector>

using namespace std;

//4 3 6 14 1 6 4 1
//22 is the max

int maxNights(vector<int> &nights, int numberOfNights);

int main() {
	vector<int> nights; 
	nights.push_back(1);
	nights.push_back(1);
	nights.push_back(1);


	cout << "Max: " << maxNights(nights, 3); 

}

int maxNights(vector<int> &nights, int numberOfNights) {
	cout << numberOfNights << " is nights." << endl;
	if(numberOfNights <= 0) {
		return 0;
	} else if(numberOfNights == 1) {
		cout << "Returned index 0" << endl;
		return nights[0];
	} else if(numberOfNights == 2) {
		cout << "Returned index 1" << endl;
		return nights[0] > nights[1] ? nights[0] : nights[1]; 
	}

	return max(maxNights(nights, numberOfNights - 1), 
			   nights[numberOfNights-1] + max(maxNights(nights, numberOfNights - 2), maxNights(nights, numberOfNights - 3))); 
}