//[1,2,3]
#include <vector>
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> currentPath; 
        permute_helper(nums, permutations, currentPath);   
        return permutations; 
    }
    
    void permute_helper(vector<int> &nums, vector<vector<int>> &permutations, vector<int> currentPath) {
        if(nums.size() == 0) {
            permutations.push_back(currentPath); 
        }
        
        int index = 0; 
        for(auto i : nums) {
            nums.erase(nums.begin() + index); 
            currentPath.push_back(i); 
            
            permute_helper(nums, permutations, currentPath); 
            
            nums.insert(nums.begin() + index, i); 
            currentPath.erase(currentPath.begin() + currentPath.size() - 1); 
            
            index++; 
        }
    }
};