class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> dp(n,true);
        dp[0]=dp[1]=false;
        for(int i=3;i<n;i++) { 
            for(int divisor=2;divisor*divisor<=i;divisor++) {
                if(i%divisor==0) {dp[i]=false; break;}
            }
        }
        return count(dp.begin(),dp.end(),true);
    }
};