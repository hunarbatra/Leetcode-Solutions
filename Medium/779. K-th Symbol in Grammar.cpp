class Solution {
public:
// O(n)
    int kthGrammar(int N, int K) {
        return bitset<32> (K-1).count()%2;
    }
};
/*
row 1-> 0
row 2-> 01
row 3-> row 2 + flip(row2) = 0110 -> on, off
row 4-> row 3 + flip(row3) = 01101001 -> on, off, off, on
row 5-> row 4 + flip(row4) = 0110100110010110 -> on, off, off, on, off, on, on, off
*/