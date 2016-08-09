class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) {
            return 0; 
        }
        int totalProfit = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[i] < prices[i+1]) {
                totalProfit += prices[i+1] - prices[i]; 
            }
        }
        return totalProfit; 
    }
};