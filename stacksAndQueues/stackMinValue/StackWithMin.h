#include <vector>

class StackWithMin {
public:
	StackWithMin();
	void push(int value); 
	void pop(); 
	int top(); 
	int minimum(); 
	bool isEmpty(); 

private:
	std::vector<int> stackVector; 
	std::vector<int> minVector; 
};