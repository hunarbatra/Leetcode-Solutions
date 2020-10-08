class Solution {
public:
    double myPow(double x, long long int n) {
        if(n<0) return 1/(x * myPow(x, -(n+1)));
        if(n == 1) return x; 
        if(n==0) return 1;
        //else return x * myPow(x, n-1);
        double t = myPow(x, n/2);
        return n & 1 ? t * t * x : t * t;
    }
};