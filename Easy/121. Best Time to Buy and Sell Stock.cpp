#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int plength = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0;i<plength;i++) {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(prices[i]-minPrice, maxProfit);
        }
        return maxProfit;
    }
};