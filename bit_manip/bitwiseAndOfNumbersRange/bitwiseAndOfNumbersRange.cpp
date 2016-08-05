class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) {
            return m; 
        }
        int lengthOfM = calculateLength(m, 0);
        int lengthOfN = calculateLength(n, 0); 

        if(lengthOfM != lengthOfN) {
            return 0; 
        } else {
            if(m & n == pow(2, lengthOfM)) {
                return pow(2, lengthOfM);
            } else {
                return calculateAndOf(m, n); 
            }
        }
    }
    
    int calculateLength(int m, int length) {
        if(m == 0) {
            return length; 
        }
        return calculateLength(m >> 1, length + 1); 
    }
    
    int calculateAndOf(int m, int n) {
        int temp1 = m; 
        int temp2 = n; 
        int indexOfDifference = 0;
        int count = 0; 
        while(m != 0) {
            int lastBitOfM = m & 1; 
            int lastBitOfN = n & 1; 
            if(lastBitOfM == 0 && lastBitOfN == 1) {
                indexOfDifference = count;
            }
            m = m >> 1; 
            n = n >> 1; 
            count++; 
        }
        int value = -1; 
        for(int i = 0; i <= indexOfDifference; i++) {
            value = value << 1; 
        }
        
        
        return temp1 & temp2 & value; 
    }
};