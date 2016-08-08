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
    vector<int> postorderTraversal(TreeNode* root) {
    
        stack<TreeNode *> nodes;
        nodes.push(root);
        vector<int> newOne;
        
        if(root == nullptr) {
            return newOne; 
        }
        
        while(!nodes.empty()) {
            TreeNode *front = nodes.top();
            nodes.pop(); 
            newOne.push_back(front->val); 
            if(front->left) 
                nodes.push(front->left);
            if(front->right) 
                nodes.push(front->right);
        }
        
        reverse(newOne.begin(), newOne.end()); 
        
        return newOne; 
    }
};