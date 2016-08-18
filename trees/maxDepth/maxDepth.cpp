    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0; 
        }
        
        return maxDepth_helper(root, 1); 
    }
    
    int maxDepth_helper(TreeNode *root, int depth) {
        if(!root) {
            return 0;
        }
        
        if(!root->left && !root->right) {
            return depth; 
        }
        
        return max(maxDepth_helper(root->left, depth+1), maxDepth_helper(root->right, depth+1)); 
    }