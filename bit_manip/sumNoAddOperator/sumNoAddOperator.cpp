// 001 
// 010 

// 100
// 100

// 10110
//  0110

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = a & b;
            a = a ^ b; 
            b = carry << 1; 
        }
        return a; 
    }
};