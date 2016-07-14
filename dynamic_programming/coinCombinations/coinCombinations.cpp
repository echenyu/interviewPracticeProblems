#include <unordered_map>
#include <iostream>

//WIP There is no dynamic programming in this one yet technically
//Might need a 2d array to do the DP
using namespace std; 

int num_paths(int n);
int countOfCoins(int n, int maxCoin);

int main() {
	int sum = 10;
	cout << num_paths(100) << " is combo" << endl;
	cout << num_paths(sum) << " is the combinations for " << sum << endl;
	cout << num_paths(sum) << " is the combo" << endl;
	cout << num_paths(25) << " is combo" << endl;
}

int num_paths(int n) {
	return countOfCoins(n, n); 
}

int countOfCoins(int n, int maxCoin) {
	static unordered_map<int, int> sumToCount; 
	if(n == 0) {
		return 1;
	} else if(n < 0) {
		return 0; 
	}
	
	int val1 = 0, val2 = 0, val3 = 0, val4 = 0; 
	if(maxCoin >= 25) {
		val1 = countOfCoins(n-25, n-25);
	}
	if(maxCoin >= 10) {
		val2 = countOfCoins(n-10, 10);
	}
	if(maxCoin >= 5) {
		val3 = countOfCoins(n-5, 5); 
	}
	if(maxCoin >= 1) {
		val4 = countOfCoins(n-1, 1); 
	}
	sumToCount[n] = val1 + val2 + val3 + val4; 
	return sumToCount[n]; 
}