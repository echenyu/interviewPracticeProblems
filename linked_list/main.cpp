#include <iostream>
#include "IntList.h"

using namespace std;

void scopeTest(IntList list) {
	return; 
}

int main() {
	IntList *list = new IntList; 
	IntList list2; 

	list->insertFront(2);
	list->insertFront(3);
	list->insertFront(10);

	list2 = *list; 
	cout << endl;
	list2.removeFront(); 

	// scopeTest(list2);  
	while(!list->isEmpty()) {
		int x = list->removeFront(); 
		cout << x << " is the value." << endl;
	}
}