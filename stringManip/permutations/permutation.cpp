//Givin 2 strings, write a method to decide if they are 
//permutations of each other

#include <string>
#include <unordered_map> 
#include <iostream>
#include <cassert>

using namespace std; 

//string1: cats string2: cat
//string1: "" string2: "" 
//string1: "c" string2: "c"
//string1: "c" string2: "d"
//string1: "taco" string2: "cato"

bool checkPermutationSort(string firstString, string secondString) {
	if(firstString.length() != secondString.length()) {
		return false; 
	}
	sort(firstString.begin(), firstString.end());
	sort(secondString.begin(), secondString.end()); 

	return !firstString.compare(secondString);  
}

bool checkPermutationHash(string firstString, string secondString) {
	if(firstString.length() != secondString.length()) {
		return false;
	}

	unordered_map<char, int> charCountHash; 

	for(int i = 0; i < firstString.length(); i++) {
		if(charCountHash[firstString[i]]) {
			charCountHash[firstString[i]]++; 
		} else {
			charCountHash[firstString[i]] = 1; 
		}
	}
	// If a char doesn't exist in the hash table or if its
	// value is 0, we know that they are not permutations of each other
	for(int i = 0; i < secondString.length(); i++) {
		if(charCountHash[secondString[i]] == 0 || !charCountHash[secondString[i]]) {
			return false; 
		} else {
			charCountHash[secondString[i]]--; 
		}
	}
	return true; 
}

int main() {
	assert(!checkPermutationSort("cats", "cat")); 
	assert(checkPermutationSort("", "" )); 
	assert(checkPermutationSort("c", "c")); 
	assert(!checkPermutationSort("c", "d")); 
	assert(checkPermutationSort("taco", "cato")); 

	assert(!checkPermutationHash("cats", "cat")); 
	assert(checkPermutationHash("", "" )); 
	assert(checkPermutationHash("c", "c")); 
	assert(!checkPermutationHash("c", "d")); 
	assert(checkPermutationHash("taco", "cato")); 
}