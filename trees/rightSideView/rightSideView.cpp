vector<int> rightSideView(TreeNode* root) {
    if(!root) return vector<int>(); 
    vector<int> res; 
    deque<TreeNode *> children; 
    deque<TreeNode *> currentLevel;
    currentLevel.push_front(root); 
    
    while(!currentLevel.empty()) {
        TreeNode *root = currentLevel.front(); 
        currentLevel.pop_front(); 
        if(root->left) children.push_back(root->left); 
        if(root->right) children.push_back(root->right); 
        
        if(currentLevel.empty()) {
            res.push_back(root->val); 
            currentLevel = children;
            children.clear(); 
        }
    }
    
    return res; 
}