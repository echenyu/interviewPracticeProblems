#include <string>
#include <iostream>
#include <algorithm> 

using namespace std;

void reverseString(string &testString); 
void reverseString2(string &testString);

int main() {
	string testString1 = "hahaThisIsString"; 
	cout << testString1; 
	reverseString(testString1); 
	cout << " is reversed to " << testString1 << endl;
	reverseString2(testString1); 
	cout << testString1 << " is reversed again w/ std swap." << endl;

	reverse(testString1.begin(), testString1.end()); 
	cout << testString1 << " is reversed by std reverse." << endl;
}

void reverseString(string &testString) {
	int index = testString.length() - 1; 

	//Can do this part with std::swap
	for(int i = 0; i < testString.length()/2; i++, index--) {
		char tempChar = testString[i]; 
		testString[i] = testString[index]; 
		testString[index] = tempChar;
	}
}

void reverseString2(string &testString) {
	int index = testString.length() - 1; 
	for(int i = 0; i < testString.length()/2; i++, index--) {
		swap(testString[i], testString[index]); 
	}
}