int removeDuplicates(vector<int>& nums) {
    int indexer = 0;
    
    for(auto num : nums) {
        if(indexer < 1 || nums[indexer-1] < num) {
            nums[indexer++] = num;
        }
    }
    
    return indexer;
}

int removeDuplicates2(vector<int>& nums) {
    int indexer = 0;
    for(auto num : nums) {
        if(indexer < 2 || num > nums[indexer-2]) {
            nums[indexer++] = num;
        }
    }
    return indexer; 
}