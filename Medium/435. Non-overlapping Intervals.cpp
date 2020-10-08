typedef pair<int, int> pi;
class Solution {
public:
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          if(intervals.size()==0) return 0;
          //sort based on finishing time
          sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) {
              return x[1]<y[1];
          });
          int remove = 0, j = 0;
          vector<vector<int>> accepted;
          accepted.push_back(intervals.front()); //first interval
          for(int i=1; i<intervals.size(); i++) {
              if(accepted[j][0] < intervals[i][1] && intervals[i][0] < accepted[j][1]) {
                  remove++;
              }
              else {
                  accepted.push_back(intervals[i]);
                  j++;
              }
          }
          return remove;
    }
};