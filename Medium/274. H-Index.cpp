class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        vector<int> count(N+1);
        for(int i : citations) {
            count[min(i, N)]++; //count for each paper
        }
        int k = N;
        for(int s = count[N]; k > s; s += count[k]) {
            k--;
        }
        return k;
    }
};