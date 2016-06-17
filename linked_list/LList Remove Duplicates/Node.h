class Node {
public:
	Node(int value_in, Node *right_in)
		: value(value_in), next(right_in)
	{}

	int value;
	Node *next;
};