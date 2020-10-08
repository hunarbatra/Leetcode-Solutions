class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        while (left < right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for (auto n : nums) sum += (n+mid-1)/mid; //to get ceiling of result
            //If the sum > threshold, the divisor is too small.
            if (sum > threshold) left = mid + 1;
            //If the sum <= threshold, the divisor is big enough.
            else right = mid;
        }
        return left;
    }
};

//RT : O(m lg n)