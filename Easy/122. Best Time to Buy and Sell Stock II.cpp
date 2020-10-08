class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) {return 0;}
        int profit = 0;
        for(int i = 0; i < prices.size()-1; ++i) {
            if(prices[i+1] > prices[i]) { //while our prices are moving up
               profit += prices[i+1] - prices[i];
           }  
        }
        return profit;
    }
};