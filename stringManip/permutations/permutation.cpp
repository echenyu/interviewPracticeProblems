#include "Permutation.h"
#include <unordered_map>
#include <iostream>

//Givin 2 strings, write a method to decide if they are 
//permutations of each other
bool Permutation::checkPermutationSort(std::string comparedString) {
	std::string tempString = stringToPermute; 
	if(tempString.length() != comparedString.length()) {
		return false; 
	}
	sort(tempString.begin(), tempString.end());
	sort(comparedString.begin(), comparedString.end()); 

	return !tempString.compare(comparedString);  
}

bool Permutation::checkPermutationHash(std::string comparedString) {
	std::string tempString = stringToPermute;
	if(tempString.length() != comparedString.length()) {
		return false;
	}

	std::unordered_map<char, int> charCountHash; 

	for(int i = 0; i < tempString.length(); i++) {
		if(charCountHash[tempString[i]]) {
			charCountHash[tempString[i]]++; 
		} else {
			charCountHash[tempString[i]] = 1; 
		}
	}
	// If a char doesn't exist in the hash table or if its
	// value is 0, we know that they are not permutations of each other
	for(int i = 0; i < comparedString.length(); i++) {
		if(charCountHash[comparedString[i]] == 0 || !charCountHash[comparedString[i]]) {
			return false; 
		} else {
			charCountHash[comparedString[i]]--; 
		}
	}
	return true; 
}

void Permutation::printPermutations() {
	printPermutationHelper(stringToPermute, ""); 
}

void Permutation::printPermutationHelper(std::string passedInString, std::string permutedString) {
	if(passedInString.size() == 0) {
		std::cout << permutedString << std::endl;
		return;
	}
	for(int i = 0; i < passedInString.size(); i++) {
		char tempChar = passedInString[i]; 
		permutedString.push_back(tempChar); 
		passedInString.erase(i, 1); 
		printPermutationHelper(passedInString, permutedString); 
		passedInString.insert(i, 1, tempChar); 
		permutedString.pop_back();
	}
}