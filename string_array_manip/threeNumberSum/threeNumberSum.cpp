#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool validThreeNumberSum(vector<int> &intVector, int sum);
bool validThreeNumberSumIterate(vector<int> &intVector, int sum);

int main() {
	vector<int> intVector; 
	for(int i = 1; i <= 10; i++) {
		intVector.push_back(i); 
	}

	int sum = 23; 
	if(validThreeNumberSumIterate(intVector, sum)) {
		cout << "There are 3 numbers that sum to " << sum << endl;
	} else {
		cout << "No 3 numbers sum to " << sum << endl;
	}
}

//O(n^2) solution and assuming elements must be unique
bool validThreeNumberSum(vector<int> &intVector, int sum) {
	unordered_map<int, vector<pair<int, int> > >pairSums; 
	for(int i = 0; i < intVector.size(); i++) {
		for(int j = i+1; j < intVector.size(); j++) {
			int sumOfPair = intVector[i] + intVector[j]; 
			if(pairSums.find(sumOfPair) == pairSums.end()) {
				pairSums[sumOfPair] = vector<pair<int, int> > (); 
			}
			pairSums[sumOfPair].push_back(make_pair(intVector[i], intVector[j])); 
		}
	}

	//Arbitrary max value
	int closestDifference = 10000; 
	int closestValue = 0; 
	for(int i = 0; i < intVector.size(); i++) {
		unordered_map<int, vector<pair<int, int> > >::iterator it;
		for(it = pairSums.begin(); it != pairSums.end(); ++it) {
			for(int j = 0; j < it->second.size(); j++) {
				if(it->second[j].first == intVector[i] || it->second[j].second == intVector[i]) {
					continue; 
				}

				if(sum - intVector[i] - it->first == 0) {
					closestValue = sum; 
					cout << "Closest value is " << closestValue; 
					return true;
				} else {
					if(abs(sum - intVector[i] - it->first) < closestDifference) {
						closestDifference = sum - intVector[i] - it->first;
						closestValue = intVector[i] + it->first;
					}
				}
			}
		}
	}
	cout << "The closest value to " << sum << " was " << closestValue << endl;

	return false; 
}

bool validThreeNumberSumIterate(vector<int> &intVector, int sum) {
	sort(intVector.begin(), intVector.end()); 

	int closestValue = 100000000; 

	for(int i = 0; i < intVector.size() - 2; i++) {
		int j = i+1; 
		int k = intVector.size() - 1; 
		while(j < k) {
			int currentSum = intVector[i] + intVector[j] + intVector[k]; 
			if(currentSum == sum) {
				return true; 
			} else if (currentSum > sum) {
				k--; 
			} else {
				j++; 
			}

			if(abs(sum - currentSum) < abs(sum - closestValue)) {
				closestValue = currentSum; 
			}
		}
	}

	cout << closestValue << " was closest to " << sum << endl;
	return false; 
}