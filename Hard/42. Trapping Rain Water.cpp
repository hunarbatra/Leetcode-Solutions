class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int> left_max(height.size()), right_max(height.size());
        int result = 0, size = height.size();
        left_max[0] = height[0];
        for(int i=1; i<size; i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[size-1] = height.back();
        for(int i=size-2; i>=0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        for(int i=0; i<size; i++) {
            result += min(left_max[i], right_max[i]) - height[i];
        }
        return result;
    }
};