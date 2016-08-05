/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        unordered_map<int, vector<vector<int>>> sumMappings;
        vector<int> currentPath; 
        pathSumHelper(root, currentPath, sum, sumMappings);
        
        vector<vector<int>> newOne; 

        if(sumMappings.find(sum) != sumMappings.end()) {
            return sumMappings[sum]; 
        }
        
        return newOne;
    }
    
    void pathSumHelper(TreeNode *root, vector<int> currentPath, int sum, unordered_map<int, vector<vector<int>>> &sumMappings) {
        if(root == nullptr) {
            return;
        }
        if(!root->left && !root->right) {
            currentPath.push_back(root->val); 
            int currentSum = 0; 
            for(int i = 0; i < currentPath.size(); i++) {
                currentSum += currentPath[i]; 
            }
            
            if(currentSum == sum) {
                if(sumMappings.find(sum) != sumMappings.end()) {
                    sumMappings[sum].push_back(currentPath);
                } else {
                    vector<vector<int>> newSumPath; 
                    newSumPath.push_back(currentPath); 
                    sumMappings[sum] = newSumPath;
                }
            }
            return; 
        }
        
        currentPath.push_back(root->val); 
        pathSumHelper(root->left, currentPath, sum, sumMappings); 
        pathSumHelper(root->right, currentPath, sum, sumMappings); 
        return; 
    }
    
};