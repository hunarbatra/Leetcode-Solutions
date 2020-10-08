class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> checkCycles;
        int sum = 0;
        if(n<1) return false;
        while(n!=1) {
            checkCycles[n]++;
            if(checkCycles[n]>1) {
                return false;
            }
           while(n>0) {
                sum += pow(n%10, 2);
                n/=10;
           }
            n = sum;
            sum=0;
        }
        return true;
    }
};