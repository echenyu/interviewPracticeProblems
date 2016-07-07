#include <iostream>
#include <unordered_map>

using namespace std;

// Take 1 step, take 2 steps, or take 3 steps
// Tribonnaci Sequence
// 
long long int numberOfWaysUpSteps(long long int numberOfSteps);

int main() {
	cout << numberOfWaysUpSteps(10) << endl; 
}

long long int numberOfWaysUpSteps(long long int numberOfSteps) {
	static unordered_map<int, long long int> calculatedWays; 
	if(numberOfSteps < 0) {
		return 0;
	} else if(numberOfSteps <= 0) {
		return 1; 
	} else if (calculatedWays.find(numberOfSteps) != calculatedWays.end()) {
		return calculatedWays[numberOfSteps]; 
	}

	calculatedWays[numberOfSteps] 
		= numberOfWaysUpSteps(numberOfSteps-1) 
		 + numberOfWaysUpSteps(numberOfSteps-2) 
		 + numberOfWaysUpSteps(numberOfSteps-3); 

	return calculatedWays[numberOfSteps]; 
}