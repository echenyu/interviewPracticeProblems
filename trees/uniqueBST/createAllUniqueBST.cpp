vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode *> res; 
    vector<int> numbers; 

    if(!n) return res; 
    
    for(int i = 1; i <= n; i++) {
        numbers.push_back(i);    
    }
    
    res = generateTrees_helper(numbers, 1, numbers.size()); 
    return res;
}

vector<TreeNode*> generateTrees_helper(vector<int> numbers, int left, int right) {
    vector<TreeNode *> res; 

    if(right-left < 0) {
        res.push_back(nullptr); 
        return res; 
    }
    if(right - left == 0) {
        res.push_back(new TreeNode(numbers[left-1])); 
        return res; 
    }
    
    for(int i = left; i <= right; i++) {
        vector<TreeNode *> leftV = generateTrees_helper(numbers, left, i-1);
        vector<TreeNode *> rightV = generateTrees_helper(numbers, i+1, right);
        
        for(int j = 0; j < leftV.size(); j++) {
            for(int k = 0; k < rightV.size(); k++) {
                TreeNode *newOne = new TreeNode(numbers[i-1]); 
                newOne->left = leftV[j]; 
                newOne->right = rightV[k]; 
                res.push_back(newOne); 
            }
        }
    }
    return res; 
}