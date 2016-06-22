#include <iostream>
#include <string>

using namespace std; 

void urlifyFromBack(string &stringToURL, int length);
void urlifyFromFront(string &stringToURL, int length);

int main() {
	string testString1 = "cat hat";
	urlifyFromBack(testString1, 7); 
	cout << testString1 << " is the result." << endl;
	testString1 = "cat hat  ";
	urlifyFromFront(testString1, 7); 
	cout << testString1 << " is the result again." << endl;
}

void urlifyFromBack(string &stringToURL, int length) {
	int endIndex = stringToURL.size() - 1; 
	int spaceCount = 0; 
	for(int i = 0; i < length; i++) {
		if(stringToURL[i] == ' ') {
			spaceCount++; 
		}
	}
	int newLength = length + spaceCount*2; 
	char *urlString = new char[newLength];
	urlString[newLength] = '\0';

	for(int i = length-1; i >= 0; i--) {
		if(stringToURL[i] == ' ') {
			urlString[newLength-1] = '0';
			urlString[newLength-2] = '2';
			urlString[newLength-3] = '%';
			newLength -= 3; 
		} else {
			urlString[newLength-1] = stringToURL[i]; 
			newLength--; 
		}
	}

	stringToURL = urlString; 
}

void urlifyFromFront(string &stringToURL, int length) {
	string newString; 
	for(int i = 0; i < length; i++) {
		if(stringToURL[i] == ' ') {
			newString.push_back('%');
			newString.push_back('2');
			newString.push_back('0'); 
		} else {
			newString.push_back(stringToURL[i]); 
		}
	}
	stringToURL = newString; 
}
