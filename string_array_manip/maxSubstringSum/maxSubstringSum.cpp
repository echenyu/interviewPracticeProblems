#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int returnValue = nums[0]; 
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i] + nums[i-1]) {
                nums[i] = nums[i] + nums[i-1];
            }
            if(nums[i] > returnValue) {
                returnValue = nums[i]; 
            }
        }
        return returnValue; 
    }
};

int main() {
    vector<int> input;
    input.push_back(-2); 
    input.push_back(1);
    input.push_back(-3);
    input.push_back(4);
    input.push_back(-1);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-5);
    input.push_back(4);
    cout << Solution::maxSubArray(input) << " is the maxsum" << endl;
}
