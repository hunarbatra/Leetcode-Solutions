class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineer;
        for(int i=0; i<n; ++i) {
            engineer.push_back({efficiency[i], speed[i]});
        }
        sort(engineer.rbegin(), engineer.rend()); //reverse sort : highest efficiency ... lowest
        priority_queue<int, vector<int>, greater<int>> pq;
        size_t sum = 0, best = 0;
        for(int i=0; i<n; ++i) {
            pq.push(engineer[i].second); //add the speed
            sum += engineer[i].second; //add speed to the sum
            if(pq.size() > k) {
                sum -= pq.top(); 
                pq.pop();
            }
            best = max(best, sum * engineer[i].first);
        }
        return best % (int)(1e9+7);
    }
};