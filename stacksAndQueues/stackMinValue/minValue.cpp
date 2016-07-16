#include <iostream>
#include <cstdlib>
#include "StackWithMin.h"

using namespace std;

int main() {
	StackWithMin newStack; 
	for(int i = 0; i < 40; i++) {
		newStack.push(rand() % 100 + 1); 
	}
	
	for(int i = 0; i < 28; i++) {
		newStack.pop(); 
	}
	cout << newStack.minimum() << " is the min." << endl;
}

