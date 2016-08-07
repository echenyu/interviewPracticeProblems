//O(n) solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0; 
        int minLength = nums.size() + 1; 
        int currentIndex = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; 
            
            while(sum >= s) {
                int length = i - currentIndex + 1; 
                if(length < minLength) {
                    minLength = length; 
                }
                sum -= nums[currentIndex++]; 
            }
        }
        
        return (minLength == nums.size() + 1) ? 0 : minLength; 
    }
};

//O(n^3) solution
class Solution {
public:
    int sum(vector<int> &nums) {
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum; 
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        if(sum(nums) < s) {
            return 0; 
        }
        
        int currentShortest = nums.size() + 1; 
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 0; j <= nums.size() - i; j++) {
                int tempSum = 0; 
                for(int k = j; k < i+j; k++) {
                    tempSum += nums[k]; 
                }
                if(tempSum >= s && i < currentShortest) {
                    currentShortest = i; 
                }
            }
        }
        return currentShortest; 
    }
};

//O(n^2) solution
class Solution {
public:

    int sum(vector<int> &nums) {
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum; 
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        if(sum(nums) < s) {
            return 0; 
        }
        
        int currentShortest = nums.size() + 1; 
        for(int i = 0; i < nums.size(); i++) {
            int currentSum = 0; 
            int j = i;
            for(j; currentSum < s && j < nums.size(); j++) {
                currentSum += nums[j]; 
            }
            int length = j - i; 
            if(length < currentShortest && currentSum >= s) {
                currentShortest = length; 
            }
            
        }
        return currentShortest; 
    }
};
