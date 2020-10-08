class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> sol;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0];
        });
        for(auto person : people) {
            sol.insert(sol.begin() + person[1], person);
        }
        return sol;
    }
};