//Given a binary search tree and the key of the node you want to remove, remove the node and return the tree



using namespace std;

class Node {
public:
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
    int key;
    Node *left, *right;
};

Node* findNode(Node* root, int key);
Node* deleteNode(Node* root, int key);


int main() {
    
    
}


/* A utility function to insert a new node with given key in BST */

Node* deleteNode(Node* root, int key) {
    Node* parentDummy = new Node(0); 
    Node* toDelete = findNode(root, key, parentDummy); 
    if(!toDelete->left) {
        parentDummy->left = 
    Node* nextParent;
    Node* moveUp = findNextNode(root->right, nextParent); 
    if(moveUp) {
        toDelete->key = moveUp->key;
        if(moveUp->right) {
            nextParent->left = moveUp->right;
        }
    }
    
    return root; 
}

Node* findNode(Node* root, int key, Node *&parent) {
    if(root->key == key) return root;
    else if(root->key > key) {
        parent = root; 
        return findNode(root->left, key); 
    }
    else {
        parent = root; 
        return findNode(root->right, key); 
    }
}

Node *findNextNode(Node *toDelete, Node *&parent) {
    if(!toDelete->right) return toDelete->left;
    if(!toDelete->left) return toDelete->right;
    Node *curr = toDelete->right;
    parent = toDelete; 
    while(curr->left) {
        parent = curr;
        curr = curr->left;
    }
    return curr;
}