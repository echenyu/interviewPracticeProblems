#include <iostream>
#include <unordered_map>

using namespace std;

bool palindromePermutation(string s);

int main() {
	string s = "ha lkaskas ha"; 
	if(palindromePermutation(s)) {	
		cout << s << " is a permutation of a palindrome" << endl;
	} else {
		cout << s << " is not. " << endl;
	}
}

bool palindromePermutation(string s) {
	unordered_map<char, bool> evenOddCountOfChar; 

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') {
			continue; 
		}
		if(evenOddCountOfChar.find(s[i]) != evenOddCountOfChar.end()) {
			evenOddCountOfChar[s[i]] = !evenOddCountOfChar[s[i]]; 
		} else {
			evenOddCountOfChar[s[i]] = false; 
		}
	}

	unordered_map<char, bool>::iterator it; 
	bool foundOdd = false; 
 
	for(it = evenOddCountOfChar.begin(); it != evenOddCountOfChar.end(); ++it) {
		if(it->second % 2 == 0) {
			if(foundOdd) {
				return false; 
			}
			foundOdd = true; 
		}
	}
	return true; 
}