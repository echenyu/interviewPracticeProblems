#include <iostream>
#include <vector>

using namespace std;

//Using a vector to represent 3 stacks.
//Note: This solution is for a fixed size stack and doesn't follow DRY principles
//We can clean it up by consolidating the functions and passing in a stack number variable instead
class TripleStack {
public:
	TripleStack() : size(0), topOfStackOneIndex(-1), topOfStackTwoIndex(-1), topOfStackThreeIndex(-1) {
		for(int i = 0; i < 999; i++) {
			stackAbstraction.push_back(-1); 
		}
	}

	int stackOneTop() { 
		return stackAbstraction[topOfStackOneIndex]; 
	}
	int stackTwoTop() {
		return stackAbstraction[topOfStackTwoIndex]; 
	}
	int stackThreeTop() {
		return stackAbstraction[topOfStackThreeIndex]; 
	} 

	void stackOnePop() {
		if(topOfStackOneIndex == 0) {
			topOfStackOneIndex = -1; 
		} else {
			topOfStackOneIndex -= 3; 
		}
	}
	void stackTwoPop() {
		if(topOfStackTwoIndex == 1) {
			topOfStackTwoIndex = -1; 
		} else {
			topOfStackTwoIndex -= 3; 
		}
	}
	void stackThreePop() {
		if(topOfStackThreeIndex == 2) {
			topOfStackThreeIndex = -1; 
		} else {
			topOfStackThreeIndex -= 3; 
		}
	}

	void stackOneInsert(int value) {
		if (topOfStackOneIndex == -1) {
			topOfStackOneIndex = 0; 
		} else {
			topOfStackOneIndex += 3; 
		}
		stackAbstraction[topOfStackOneIndex] = value; 
	}
	void stackTwoInsert(int value) {
		if (topOfStackTwoIndex == -1) {
			topOfStackTwoIndex = 1; 
		} else {
			topOfStackTwoIndex += 3; 
		}
		stackAbstraction[topOfStackTwoIndex] = value; 
	}
	void stackThreeInsert(int value) {
		if (topOfStackThreeIndex == -1) {
			topOfStackThreeIndex = 2; 
		} else {
			topOfStackThreeIndex += 3; 
		}
		stackAbstraction[topOfStackThreeIndex] = value; 
	}

	bool stackOneIsEmpty() {
		if(topOfStackOneIndex == -1) {
			return true; 
		}
		return false; 
	}

	bool stackTwoIsEmpty() {
		if(topOfStackTwoIndex == -1) {
			return true; 
		}
		return false; 
	}

	bool stackThreeIsEmpty() {
		if(topOfStackThreeIndex == -1) {
			return true; 
		}
		return false; 
	}

private:
	int topOfStackOneIndex; 
	int topOfStackTwoIndex; 
	int topOfStackThreeIndex; 
	int size; 
	vector<int> stackAbstraction; 
};

int main() {
	TripleStack newTripleStack; 
	for(int i = 0; i < 30; i++) {
		newTripleStack.stackOneInsert(i); 
		newTripleStack.stackTwoInsert(i+1); 
		newTripleStack.stackThreeInsert(i+2); 
	}

	while(!newTripleStack.stackTwoIsEmpty()) {
		cout << newTripleStack.stackTwoTop() << " ";
		newTripleStack.stackTwoPop(); 
	}
	cout << endl;
}
