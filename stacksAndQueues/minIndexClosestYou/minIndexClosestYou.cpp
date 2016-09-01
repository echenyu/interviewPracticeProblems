#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std; 

vector<int> prevSmaller(vector<int> &A);

int main() {
    cout << "hello world" << endl;
    vector<int> A = {2,4,5,3, 5};
    vector<int> res = prevSmaller(A); 
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}


/* G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]

Input : A : [4, 5, 2, 10]
Return :    [-1, 4, -1, 2] */
                         
vector<int> prevSmaller(vector<int> &A) {
    vector<int> res(A.size(), -1); 
    stack<int> minVals; 
    for(int i = 0; i < A.size(); i++) {
        if(!minVals.empty()) {
            while(minVals.top() > A[i]) {
                minVals.pop(); 
            }
            res[i] = minVals.top();
        }
        
        minVals.push(A[i]);
    }
    
    return res; 
}