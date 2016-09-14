#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);
bool searchMatrix_helper(vector<vector<int>> &matrix, int target, int start, int end);

int main() {
    vector<vector<int>> matrix = {{1, 3}}; 
    cout << searchMatrix(matrix, 2) << endl;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false; 
        int startIndex = 0, endIndex = matrix.size() * matrix[0].size() - 1; 
        return searchMatrix_helper(matrix, target, startIndex, endIndex); 
    }
    
bool searchMatrix_helper(vector<vector<int>> &matrix, int target, int start, int end) {
    if(start > end) {
        return false; 
    }
    
    int mid = start + (end - start)/2; 
    cout << mid << " is the mid" << endl;
    //calculate the indices to look at
    int row = 0; 
    int col = mid; 
    while(col / matrix[0].size()) {
        row++; 
        col /= matrix[0].size();
    }
    
    int val = matrix[row][col]; 
    if(val > target) {
        return searchMatrix_helper(matrix, target, start, mid - 1); 
    } else if(val < target) {
        return searchMatrix_helper(matrix, target, mid+1, end); 
    } else {
        return true; 
    }
}