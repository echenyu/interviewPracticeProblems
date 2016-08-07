class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets_helper(nums);
    }
    
    vector<vector<int>> subsets_helper(vector<int> &nums) {
        if(nums.size() == 0) {
            vector<int> newVector;
            vector<vector<int>> subsetVector(1, newVector); 
            return subsetVector; 
        }
        
        int valuePopped = nums[0];
        nums.erase(nums.begin()); 
        vector<vector<int>> newVector = subsets_helper(nums); 
        return createNewSubsets(newVector, valuePopped); 
    }
    
    vector<vector<int>> createNewSubsets(vector<vector<int>> &nums, int value) {
        vector<vector<int>> numsToAppend; 
        for(int i = 0; i < nums.size(); i++) {
            vector<int> tempVector = nums[i]; 
            tempVector.push_back(value); 
            numsToAppend.push_back(tempVector); 
        }
        for(int i = 0; i < numsToAppend.size(); i++) {
            nums.push_back(numsToAppend[i]); 
        }
        return nums; 
    }
};