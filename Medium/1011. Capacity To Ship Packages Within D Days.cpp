class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        if(weights.empty() || D == 0) return 0;
        int left = 0, right = 0;
        for(auto w: weights) left = max(left, w), right += w;
        if(D == weights.size()) return left;
        while(left < right) {
            int mid = (left + right) / 2;
            int curr_days = 1, curr_bagsize = 0;
            for(auto w : weights) {
                if(curr_bagsize + w > mid) { //exceeds our current bag limit i.e mid
                    //add further weights to the next bag
                    //and test if it fits within the given D days
                    curr_days++; curr_bagsize = 0;
                }
                curr_bagsize += w;
            }
            if(curr_days > D) left = mid + 1; //we need bigger bag sizes to accomodate
            else right = mid; //lets test smaller bag sizes as it looks we've maybe extra space
        }
        return left;
    }
};
/*
RT : Time - O(w lg n) -> where n == totalSum - maxEl; w = no. of weights
(in every binary search we move left/right based upon the caclulations in our for loop which
takes O(w) time)
Space : O(1) -> inplace
*/
