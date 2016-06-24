class Node {
public:
	Node() 
		:left(0), right(0), value(-1) {}
		
	Node(Node *left_in, Node *right_in, int value_in)
		: left(left_in), right(right_in), value(value_in)
	{
	}

	Node *left;
	Node *right; 
	int value; 
};