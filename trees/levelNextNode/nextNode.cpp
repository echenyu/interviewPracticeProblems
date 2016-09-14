#include <iostream>

using namespace std; 

struct Node {
    Node() : left(nullptr), right(nullptr), next(nullptr) {}
    Node *left;
    Node *right;
    Node *next; 
    int val; 
};

Node *getNext(Node *root, Node *left, bool isLeft) {
    if(isLeft && root->right) return root->right;
    Node *next = root->next;
    while(next) {
        cout << "Looking at:" << next->val<< endl;
        if(next->left) {
            cout << "here";
            return next->left;
        }
        if(next->right) {
            cout << "here";
            return next->right;
        }
        next = next->next;
    }
    return nullptr;
}

void connect(Node *root) {
    if(!root) return;
    cout << "Current Node: " << root->val << endl;
    if(root->left) {
        root->left->next = getNext(root, root->left, 1); 
        cout << endl;
    }
    if(root->right) {
        root->right->next = getNext(root, root->right, 0); 
        cout << endl;
    }
    
    connect(root->right); 
    connect(root->left);
}

