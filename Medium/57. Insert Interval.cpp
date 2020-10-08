class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur][1] < newInterval[0]) {
            result.push_back(intervals[cur]);
            cur++;
        }
        while (cur < n && intervals[cur][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            cur++;
        }
        result.push_back(newInterval);
        while(cur < n) result.push_back(intervals[cur++]);
        return result;
    }
};