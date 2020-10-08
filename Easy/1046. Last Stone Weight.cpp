class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty()) return 0;
        priority_queue<int> pq; //maxheap
        for(auto s : stones) pq.push(s);
        while(!pq.empty()) {
            if(pq.size() == 1) return pq.top(); //if one element
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            if(first == second) continue; //smash em' a.k.a remove both :)
            else if(second < first) pq.push(first-second);
        }
        return 0;
    }
};