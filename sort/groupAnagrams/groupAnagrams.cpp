#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void groupAnagrams(vector<string> &stringVector);
void groupAnagramsRadix(vector<string> &stringVector);

int main() {
	vector<string> stringVector; 
	stringVector.push_back("haha"); 
	stringVector.push_back("lol"); 
	stringVector.push_back("ahha"); 
	stringVector.push_back("pizza"); 
	stringVector.push_back("ahah"); 

	groupAnagramsRadix(stringVector); 
	for(int i = 0; i < stringVector.size(); i++) {
		cout << stringVector[i] << " ";
	}
	cout << endl;
}

//haha lol ahha pizza ahah
//Complexity is O(n^2 * m) where m is length of string and n = number of elements inv ector
void groupAnagrams(vector<string> &stringVector) {

	for(int i = 0; i < stringVector.size(); i++) {
		int indexToSwapWith = i+1; 
		string stringToCompare1 = stringVector[i];
		sort(stringToCompare1.begin(), stringToCompare1.end()); 
		for(int j = i+1; j < stringVector.size(); j++) {
			string stringToCompare2 = stringVector[j]; 
			sort(stringToCompare2.begin(), stringToCompare2.end()); 
			if(stringToCompare1 == stringToCompare2) {
				swap(stringVector[j], stringVector[indexToSwapWith]);
				indexToSwapWith++;  
			}
		}
		i = indexToSwapWith; 
	}
}

void groupAnagramsRadix(vector<string> &stringVector) {
	unordered_map<string, vector<string> > listOfAnagrams; 
	for(int i = 0; i < stringVector.size(); i++) {
		string currentString = stringVector[i]; 
		sort(currentString.begin(), currentString.end()); 
		if(listOfAnagrams.find(currentString) == listOfAnagrams.end()) {
			listOfAnagrams[currentString] = vector<string>(); 
		}
		listOfAnagrams[currentString].push_back(stringVector[i]); 
	}

	unordered_map<string, vector<string> >::iterator it; 
	int currentIndex = 0; 

	for(it = listOfAnagrams.begin(); it != listOfAnagrams.end(); ++it) {
		vector<string> currentAnagrams = it->second; 
		for(int i = 0; i < currentAnagrams.size(); i++) {
			stringVector[currentIndex] = currentAnagrams[i]; 
			currentIndex++; 
		}
	}
}