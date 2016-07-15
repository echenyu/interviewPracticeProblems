#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2);
bool isSubstring(string s1, string s2);

int main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat"; 
	if(isRotation(s1, s2)) {
		cout << s2 << " is a rotation of " << s1 << endl;
	}
}

bool isRotation(string s1, string s2) {
	if(s1.size() != s2.size()) {
		return false; 
	}
	s2 = s2 + s2; 
	if(isSubstring(s1, s2)) {
		return true;
	}
	return false; 
}

//Compare two strings to see if one is a substring of the other
//Iterate through the longer string's length,
//	If at some index i, the longerString[i] equal to shorterString[0]
//	We will enter into a second for loop that compares to see if shorter string
//	and longer string starting from index i are the same
bool isSubstring(string s1, string s2) {
	string longerString = (s1.size() > s2.size()) ? s1 : s2; 
	string shorterString = (s1.size() > s2.size()) ? s2 : s1; 

	for(int i = 0; i < longerString.size(); ++i) {
		if(longerString[i] == shorterString[0]) {
			int longerStringIndexer = i+1; 
			for(int j = 1; j < shorterString.size(); ++j) {
				if(longerString[longerStringIndexer] != shorterString[j]) {
					break; 	
				}
				longerStringIndexer++; 
			}
			return true; 
		}
	}
	return false; 
}