class Solution {
public:
    int climbStairs(int n) {
        //Dynamic Programming
        //Lets make an array to store the result of subproblems
        int lookup[n+1];
        lookup[0]=1;
        lookup[1]=1;
        for(int staircase=2;staircase<=n;staircase++) {
            lookup[staircase]= lookup[staircase-1] + lookup[staircase-2];
            //bottom-up approach as we consider last 2 calculations
        }
        return lookup[n];
    }
};