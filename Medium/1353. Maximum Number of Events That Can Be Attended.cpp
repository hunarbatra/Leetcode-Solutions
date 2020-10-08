class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        //Approach 2
         if(events.empty()) return 0;
        //sort based on finishing time
        sort(events.begin(), events.end(), [](vector<int> a, vector<int> b) {
            if(a[1]==b[1]) return a[0]<b[0];
            else return a[1]<b[1];
        });
        unordered_set<int> hashset;
        for(int curr_event=0; curr_event<events.size(); curr_event++) {
            for(int curr_day=events[curr_event][0]; curr_day<=events[curr_event][1]; curr_day++) {
                if(hashset.find(curr_day) == hashset.end()) {
                    hashset.insert(curr_day);
                    break;
                }
            }
        }
        return hashset.size();
    } 
        //Approach 1 - O(n^2)
       /* if(events.empty()) return 0;
        //sort based on finishing time
        sort(events.begin(), events.end(), [](vector<int> a, vector<int> b) {
            if(a[1]==b[1]) return a[0]<b[0];
            else return a[1]<b[1];
        });
        int maxdaysize = events.back()[1];
        vector<bool> dp(maxdaysize+1, false); //true->event has been scheduled
        for(int curr_event=0; curr_event<events.size(); curr_event++) {
            for(int curr_day=events[curr_event][0]; curr_day<=events[curr_event][1]; curr_day++) {
                if(!dp[curr_day]) { //if this day is empty
                    dp[curr_day] = true; //we schedule an event
                    break;
                }
            }
        }
        return count(dp.begin(), dp.end(), true);
    } */
};