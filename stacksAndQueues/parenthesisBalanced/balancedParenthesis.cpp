#include <iostream>
#include <stack>
#include <utility>

using namespace std;

bool parenthesisBalanced(string s);
void makeStringBalanced(string &s);

//Example of making string balanced
// “ab(c)”      =>    “ab(c)”
// “)asdf)”     =>     “asdf”
// “(a((d)ff)”  =>     “a((d)ff)” || “(a(d)ff)”
// “)(“         =>     “”

int main() {
	string s = "()";
	string s1 = ")()(";
	string s2 = "(()())"; 

	string s3 = "ab(c)";
	string s4 = ")asdf)";
	string s5 = "(a((d)ff)";
	string s6 = ")(";

	cout << parenthesisBalanced(s) << " is our value." << endl;
	cout << parenthesisBalanced(s1) << " is our value." << endl;
	cout << parenthesisBalanced(s2) << " is our value." << endl;
	cout << parenthesisBalanced(s3) << " is our value." << endl;
	cout << parenthesisBalanced(s4) << " is our value." << endl;
	cout << parenthesisBalanced(s5) << " is our value." << endl;
	cout << parenthesisBalanced(s6) << " is our value." << endl;
	cout << endl;
	makeStringBalanced(s1); 
	makeStringBalanced(s3); 
	makeStringBalanced(s4); 
	makeStringBalanced(s5); 
	makeStringBalanced(s6); 
	cout << "Making strings balanced now!" << endl;
	cout << s1 << " " << parenthesisBalanced(s1) << " is our value." << endl;
	cout << s3 << " " << parenthesisBalanced(s3) << " is our value." << endl;
	cout << s4 << " " << parenthesisBalanced(s4) << " is our value." << endl;
	cout << s5 << " " << parenthesisBalanced(s5) << " is our value." << endl;
	cout << s6 << " " << parenthesisBalanced(s6) << " is our value." << endl;
	
}

bool parenthesisBalanced(string s) {
	stack<char> parenthesisStack;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			parenthesisStack.push('('); 
		} 
		if(s[i] == ')') {
			if(parenthesisStack.empty()) {
				return false; 
			} else {
				parenthesisStack.pop(); 
			}
		}
	} 

	return parenthesisStack.empty(); 
}

void makeStringBalanced(string &s) {
	if(parenthesisBalanced(s)) {
		return;
	}

	stack<pair<int, char> > indicesToRemove; 
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			indicesToRemove.push(make_pair(i, '(')); 
		}
		if(s[i] == ')') {
			if(indicesToRemove.empty() || indicesToRemove.top().second != '(') {
				indicesToRemove.push(make_pair(i, ')')); 
			} else {
				indicesToRemove.pop(); 
			}
		}
	}

	string sBuffer; 
	for(int i = s.size() - 1; i >= 0; i--) {
		if(i == indicesToRemove.top().first) {
			indicesToRemove.pop(); 
			continue; 
		}
		sBuffer.insert(sBuffer.begin(), s[i]); 
	}
	s = sBuffer; 
}