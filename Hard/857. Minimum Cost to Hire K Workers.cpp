class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        vector<vector<double>> workers;
        for (int i=0; i<q.size(); ++i) {
            workers.push_back({(double)w[i]/q[i], (double)q[i]});
        }
        //sort based on wage:quality ratio
        sort(workers.begin(),workers.end());
        double best = DBL_MAX, sum = 0;
        priority_queue<int> pq;
        for(int i=0; i<workers.size(); ++i) {
            sum += workers[i][1];
            pq.push(workers[i][1]);
            if(pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == K) {
                best = min(best, sum * workers[i][0]);
            }
        }
        return best;
    }
};