#include <iostream>
#include <unordered_map>

//Note this only works for US Currency because no matter what, we would
//choose the largest coin because 5 and 10 will always be factors of multiples of 25

using namespace std; 

int minNumberOfCoins(int n, int count, int arr[]);

int main() {
	int *arr = new int[999999]; 
	for(int i = 0; i < 999999; i++) {
		arr[i] = -1; 
	}
	cout << "Min coins to get: " << 100 << " is: " << minNumberOfCoins(999999, 0, arr) << endl;

}

int minNumberOfCoins(int n, int count, int arr[]) {
	
	if(n == 0) {
		return count;  
	}
	
	// if(arr[n-25] != -1) {
	// 	arr[n] = arr[n-25] + 1; 
	// 	return arr[n]; 
	// } else if(arr[n-10] != -1) {
	// 	arr[n] = arr[n-10] + 1; 
	// 	return arr[n]; 
	// } else if(arr[n-5] != -1) {
	// 	arr[n] = arr[n-5] + 1; 
	// 	return arr[n]; 
	// } else if(arr[n-1] != -1) {
	// 	arr[n] = arr[n-5] + 1; 
	// 	return arr[n]; 
	// }

	if(n >= 25) {
		arr[n] = minNumberOfCoins(n-25, count+1, arr); 
	} else if(n >= 10) {
		arr[n] = minNumberOfCoins(n-10, count+1, arr); 
	} else if(n >= 5) {
		arr[n] = minNumberOfCoins(n-5, count+1, arr);  
	} else {
		arr[n] = minNumberOfCoins(n-1, count+1, arr); 
	}

	return arr[n]; 
}