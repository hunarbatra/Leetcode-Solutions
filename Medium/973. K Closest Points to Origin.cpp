class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            return sqrt(pow(0-a[0], 2) + pow(0-a[1], 2)) < sqrt(pow(0-b[0], 2) + pow(0-b[1], 2));
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

/*
Distance Formula :
  ---------------------------
 / (x2 - x1)^2 + (y2 - y1)^2
-
*/