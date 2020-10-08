class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end()); //sorting the coins so that we have smallest at coins[0]
        vector<int> lookup(amount+1,amount+1); //because if its 11, then we need 0....11 i.e 12 slots and initialised vector to amount+1 i.e greater that max amount
        lookup[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]<=i)
                {
                    lookup[i]=min(lookup[i], lookup[i-coins[j]] +1);
                }
                else break;
            }
        }
        return lookup[amount]>amount?-1:lookup[amount];
    }
};