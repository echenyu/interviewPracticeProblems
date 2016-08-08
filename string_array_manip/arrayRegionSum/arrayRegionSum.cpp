class NumArray {
public:
    NumArray(vector<int> &nums) {
        nums_in = nums; 
        
        for(int i = 1; i < nums.size(); i++) {
            nums_in[i] = nums_in[i] + nums_in[i-1]; 
        }
    }

    int sumRange(int i, int j) {
        return (i == 0) ? nums_in[j] : nums_in[j] - nums_in[i-1]; 
    }
private:
    vector<int> nums_in; 
};

