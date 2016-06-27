#include <vector>
class Node {
public:
	Node() 
		:value(-1), visited(false) {}
		
	Node(std::vector<Node *> children_in, int value_in)
		: children(children_in), value(value_in), visited(false)
	{
	}

	std::vector<Node *> children; 
	int value; 
	bool visited; 
};