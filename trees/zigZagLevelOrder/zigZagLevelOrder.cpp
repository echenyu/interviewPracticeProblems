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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode *> currentLevel; 
        deque<TreeNode *> children; 
        
        currentLevel.push_back(root); 
        bool levelIsQueue = true; 
        
        vector<int> currentLevelVector; 
        vector<vector<int>> res; 
        
        while(!currentLevel.empty()) {
            if(levelIsQueue) {
                if(currentLevel.front()) {
                    currentLevelVector.push_back(currentLevel.front()->val); 
                    children.push_back(currentLevel.front()->left); 
                    children.push_back(currentLevel.front()->right); 
                }
                
                currentLevel.pop_front(); 
            } else {
                if(currentLevel.back()) {
                    currentLevelVector.push_back(currentLevel.back()->val); 
                    children.push_front(currentLevel.back()->right); 
                    children.push_front(currentLevel.back()->left); 
                }
                
                currentLevel.pop_back(); 
            }
            
            if(currentLevel.empty()) {
                levelIsQueue = !levelIsQueue;
                if(currentLevelVector.size() > 0)
                    res.push_back(currentLevelVector); 
                    
                currentLevel = children; 
                
                children.clear();
                currentLevelVector.clear(); 
            }
        }
        
        return res; 
    }
};