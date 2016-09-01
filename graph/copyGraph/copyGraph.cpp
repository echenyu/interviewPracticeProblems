#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//300 million people
//200000 people who are authors
//2 books a year
//400000

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

struct Node {
    int label;
    vector<Node *> neighbors;
    Node(int x) : label(x) {}; 
}; 

Node *cloneGraph(Node *node);
Node *cloneGraph_helper(Node *curr, unordered_map<int, Node *> &existingNodes);
void printGraph(Node *curr);

int main() {
    Node *first = new Node(1); 
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4); 
    first->neighbors.push_back(second); 
    first->neighbors.push_back(third); 
    first->neighbors.push_back(fourth); 
    second->neighbors.push_back(first); 
    second->neighbors.push_back(third); 
    third->neighbors.push_back(second); 
    fourth->neighbors.push_back(first); 
    
    Node *newGraph = cloneGraph(first); 
    printGraph(newGraph); 
}

Node *cloneGraph(Node *node) {
    unordered_map<int, Node *> existingNodes; 
    return cloneGraph_helper(node, existingNodes); 
}
                      
Node *cloneGraph_helper(Node *curr, unordered_map<int, Node *> &existingNodes) {
    if(existingNodes.find(curr->label) == existingNodes.end()) {
        Node *newNode = new Node(curr->label); 
        existingNodes[curr->label] = newNode;
        for(auto i : curr->neighbors) {
            if(existingNodes.find(i->label) != existingNodes.end()) {
                newNode->neighbors.push_back(existingNodes[i->label]);
            } else {
                newNode->neighbors.push_back(cloneGraph_helper(i, existingNodes)); 
            }
        }
    }
    
    return existingNodes[curr->label]; 
}

void printGraph(Node *curr) {
    static unordered_set<Node *> seenNodes; 
    if(seenNodes.find(curr) != seenNodes.end()) return;
    
    seenNodes.insert(curr); 
    cout << "Node: " << curr->label << " has neighbors: " << endl;
    for(auto i : curr->neighbors) {
        cout << "Node: " << i << " with: " << i->label << endl;
    }
    cout << endl;
    for(auto i : curr->neighbors) {
        printGraph(i); 
    }
}
                       
//Clone an undirected graph
//Each node contains a label and a list of neighbors
//Node 1: Neighbors - 2, 3, 4
//Node 2: Neighbors - 1, 3
//Node 3: Neighbors - 2
//Node 4: Neighbors - 1
//Keep track of a hash table, label -> Node *