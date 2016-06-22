#include <cassert>
#include <iostream>

class IntList {
public:
	IntList() : head(0), tail(0) { } 
	~IntList() {
		removeAll(); 
	}

	// IntList(const IntList &other) :head(0), tail(0) {
	// 	copyAll(other); 
	// }

	// IntList &operator=(const IntList &other) {
	// 	if(this == &other) return *this; 
	// 	removeAll();
	// 	copyAll(other); 
	// 	return *this; 
	// }

	bool isEmpty() const {
		if(head == 0) {
		return true;
		}
		return false;
	}

	void insertFront(int i) {
		Node *newNode = new Node; 
		newNode->next = head; 
		newNode->val = i; 
		if(isEmpty()) {
			head = tail = newNode; 
		} else {
			head = newNode; 
		}
		std::cout << newNode << " is the memory." << std::endl;
	}

	void insertBack(int i) {
		Node *newNode = new Node; 
		newNode->next = 0; 
		newNode->val = i; 
		if(isEmpty()) {
			head = tail = newNode; 
		} else {
			tail->next = newNode; 
			tail = newNode; 
		}
	}

	int removeFront() {
		assert(!isEmpty()); 
		Node *current = head; 
		std::cout << current << std::endl;
		std::cout << "Again?" << std::endl;
		int value = head->val;
		std::cout << value << std::endl;
		head = current->next; 
		std::cout << head->val << std::endl;
		delete current; current = 0;
		return value; 
	}

private:
	struct Node {
		Node *next; 
		int val; 
	};

	Node *head; 
	Node *tail; 
	void removeAll() {
		while(!isEmpty()) {
			removeFront(); 
		}
	}

	void copyAll(const IntList &other) {
		Node *current = other.head; 
		while(current) {
			int val = current->val; 
			insertBack(val); 
			current = current->next; 
		}
	}
};