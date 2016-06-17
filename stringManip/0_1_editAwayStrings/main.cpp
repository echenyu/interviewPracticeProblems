#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

//There are 3 types of edits that can be performed on a string, insert, remove, or replace. 
//Given 2 strings, write a function to check if they are 1 or 0 edits away.
bool similarStrings(string firstString, string secondString);

int main () {
	cout << similarStrings("hello", "hell") << endl; 
	cout << similarStrings("pale", "bale") << endl; 
	cout << similarStrings("laksd", "alksd") << endl; 
}

bool similarStrings(string firstString, string secondString) {
	if(fabs(firstString.length() - secondString.length()) > 1) {
		return false; 
	}

	string longerString; 
	string shorterString; 
	(firstString.length() > secondString.length()) ? longerString = firstString : longerString = secondString; 
	(firstString.length() > secondString.length()) ? shorterString = secondString : shorterString = firstString; 
	// Check replacements

	int differences = 0; 
	for(int i = 0; i < firstString.length(); i++) {
		if(firstString[i] != secondString[i]) {
			differences++; 
		}
		if(differences > 1) {
			return false; 
		}
	}

	if(shorterString.length() > longerString.length() || longerString.length() > shorterString.length()) {
		for(int j = 0; j < shorterString.length(); ++j){ 
			if(shorterString[j] != longerString[j]) {
				if(shorterString[j] != longerString[j+1]) {
					cout << "more than one removed." << endl;
					return false; 
				}
			}
		}
	}
	return true; 
}