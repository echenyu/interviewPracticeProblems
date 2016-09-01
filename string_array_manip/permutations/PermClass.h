#include <vector>
#include <cmath>

using namespace std; 

class PermClass {
public:
    PermClass(vector<int> nums, bool n) {
        if(n) {
            curr = nums;
            original = nums;
        } else {
            original = nums; 
            allPermutations(original, vector<int>()); 
        } 
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        curr = original;
        return curr; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle(bool n) {
        if(n) {
            curr.clear(); 
            createPermutation(original, curr); 
            return curr; 
        } else {
            int val = rand() % permutations.size(); 
            curr = permutations[val];
            return curr; 
        }
    }
    
private:
    void createPermutation(vector<int> values, vector<int> &nextPerm) {
        if(values.size() == 0) return; 
        int indexToAdd = rand() % values.size(); 
        int nextVal = values[indexToAdd]; 
        nextPerm.push_back(nextVal); 
        values.erase(values.begin() + indexToAdd); 
        createPermutation(values, nextPerm); 
    }

    void allPermutations(vector<int> values, vector<int> currentPermutation) {
        if(values.size() == 0) {
            permutations.push_back(currentPermutation); 
        }

        for(int i = 0; i < values.size(); i++) {
            int val = values[i];
            currentPermutation.push_back(val); 
            values.erase(values.begin() + i); 
            allPermutations(values, currentPermutation); 
            values.insert(values.begin() + i, val); 
            currentPermutation.pop_back(); 
        }
    }
    vector<int> curr; 
    vector<int> original;
    vector<vector<int>> permutations; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */