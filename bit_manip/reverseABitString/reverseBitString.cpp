#include <iostream>

using namespace std;

class Solution {
public:
    static uint32_t reverseBits(uint32_t n) {
        uint32_t returnValue = 0; 
        cout << (returnValue << 1) << endl;
        int currentIndex = 0; 
        for(int i = 31; i >= 0; i--) {
            uint32_t temp = n; 
            uint32_t bitToAdd = 1; 
            bitToAdd = ((bitToAdd << i) & temp) >> i << currentIndex;
            returnValue = returnValue | bitToAdd; 
            currentIndex++;
        }
        
        return returnValue; 
    }

    //Better solution
    uint32_t reverseBits2(uint32_t n) {
        uint32_t result= 0;
        for(int i=0; i<32; i++)
            result = (result<<1) + (n>>i &1);
        
        return result;
    }
};

int main() {
    uint32_t randomInt = 230918; 
    cout << Solution::reverseBits(randomInt) << endl;
}