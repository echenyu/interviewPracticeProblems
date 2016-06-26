// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

// Hash Tables
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std; 

// Empty Case: "" -> return true;
// 1 letter string: "c" --> return true; 
// no duplicates: "Cat" --> return true;
// duplicates: "Google" --> return false; 
// $%67$
// adsjklflkajsdlkfjlaksdjflkjasldfkj19380981039840918

bool allUniqueCharacters(string stringToTestOn) {
	unordered_set<char> uniqueChars; 
	for(int i = 0; i < stringToTestOn.length(); i++) {
		if(uniqueChars.find(stringToTestOn[i]) != uniqueChars.end()) {
			return false; 
		} else {
			uniqueChars.insert(stringToTestOn[i]); 
		}
	}
	return true; 
}


bool allUniqueCharacters2(string stringToTestOn) {
	if(stringToTestOn.size() == 0) {
		return true; 
	}
	sort(stringToTestOn.begin(), stringToTestOn.end()); 
	for(int i = 0; i < stringToTestOn.length()-1; i++) {
		if(stringToTestOn[i] == stringToTestOn[i+1]) {
			return false; 
		}
	}
	return true; 
}

int main() {
	string test = "";
	string test2 = "c";
	string test3 = "cats";
	string test4 = "google";

	assert(allUniqueCharacters(test)); 
	assert(allUniqueCharacters(test2));
	assert(allUniqueCharacters(test3)); 
	assert(!allUniqueCharacters(test4)); 
	assert(allUniqueCharacters2(test)); 
	assert(allUniqueCharacters2(test2));
	assert(allUniqueCharacters2(test3)); 
	assert(!allUniqueCharacters2(test4)); 
}