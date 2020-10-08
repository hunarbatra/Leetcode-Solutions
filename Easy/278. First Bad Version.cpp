// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n;
        while(left < right) {
            long long mid = (left+right) / 2;
            if(isBadVersion(mid) == false) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

//RT : O(lg n) & Space : O(1)