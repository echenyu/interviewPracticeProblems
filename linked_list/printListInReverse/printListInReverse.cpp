#include <iostream>
#include "../Node.h"
#include <stack>
//Node question - function that iterates over
//a linked list in reverse

// Standard case - 4 nodes - 1 2 3 4
// Corner case - empty list
// Single case - 1 
using namespace std;

int calculateLengthOfLinkedList(Node *head);

int main() {
  
  return 0; 
}

//outerLength = 4
//length = 4
//length = 3 Node * @ 2
//length = 2 Node * @ 3
//length = 1 Node * @ 4
//outerLength = 3 length = 3 head Node * @ 1

void printNodesInReverse(Node *head) {
  int length = calculateLengthOfLinkedList(head);
  int outerLength = length; 
  Node *tempHead = head; 
  
  while(outerLength != 0){
    while(length != 0) {
      head = head->next; 
      length--; 
    }
  
    cout << head->value << " "; 
    head = tempHead; 
    length = outerLength-1; 
    outerLength--; 
  }
}

void printNodesInReverseStack(Node *head) {
  stack<int> reverseList; 
  while(head != nullptr) {
    reverseList.push(head->value); 
    head = head->next; 
  }
  
  while(!reverseList.empty()) {
    cout << reverseList.top() << " "; 
    reverseList.pop(); 
  }
}

void printNodesRecursively(Node *head) {
  if(head == nullptr) {
    return;
  }
  
  printNodesRecursively(head->next); 
  cout << head->value << " "; 
}

// 1 -> 2 -> 3 -> 4 

int calculateLengthOfLinkedList(Node *head) {
  int count = 0; 
  
  while(head != nullptr) {
    count++; 
    head = head->next; 
  }
  
  return count; 
}