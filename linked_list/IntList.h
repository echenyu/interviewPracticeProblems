class IntList {
public:
	IntList();
	~IntList();
	IntList(const IntList &other);
	IntList &operator=(const IntList &other);

	bool isEmpty() const;
	void insertFront(int i);
	void insertBack(int i);
	int removeFront();

private:
	struct Node {
		Node *next; 
		int val; 
	};

	Node *head; 
	Node *tail; 
	void removeAll(); 
	void copyAll(const IntList &other);
};