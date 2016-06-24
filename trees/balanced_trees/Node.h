class Node {
public:
	Node() 
		:left(0), right(0), tree_depth(-1)
		
	Node(Node *left_in, Node *right_in)
		: left(left_in), right(right_in), tree_depth(-1)
	{
	}

	Node *left;
	Node *right; 
	int tree_depth; 
};