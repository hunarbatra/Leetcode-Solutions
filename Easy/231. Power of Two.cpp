class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & (n-1));
    }
};
/* EG :
n = 4 --> 100
n-1 = 3 --> 011
100 & 011 == 000
*/
