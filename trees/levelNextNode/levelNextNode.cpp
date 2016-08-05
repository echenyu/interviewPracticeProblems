/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        stack<TreeLinkNode *> currentLevel; 
    	stack<TreeLinkNode *> childrenLevel; 
    
    	currentLevel.push(root); 
    	TreeLinkNode *prev = nullptr; 
    	TreeLinkNode *current = nullptr;
    	while(!currentLevel.empty()) {
    		current = currentLevel.top(); 
    		currentLevel.pop(); 
    		current->next = prev; 
    		prev = current; 
    
    		if(current->left != nullptr) {
    			childrenLevel.push(current->left); 
    		} 
    		if(current->right != nullptr) {
    			childrenLevel.push(current->right); 
    		}
    
    		if(currentLevel.empty()) {
    			currentLevel = childrenLevel; 
    			while(!childrenLevel.empty()) {
    				childrenLevel.pop(); 
    			}
    			prev = nullptr; 
    		}
    	}

    }
};