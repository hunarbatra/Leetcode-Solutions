class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](string& s) {
            return count(s.begin(), s.end(), *min_element(s.begin(), s.end()));
        };
        unordered_map<int,int> counter; // val -> count
        vector<int> result;
        for(string w : words) {
            counter[f(w)]++;
        }
        for(string q : queries) {
            int curr_count = f(q);
            int cnt = 0;
            for(int i=curr_count+1; i<=10; i++) {//optimization
                if(counter[i]!=0)
                    cnt += counter[i];
            }
            result.push_back(cnt);
        }
        return result;
    }
};
/*
we start int i at curr_count+1 ... 10 because length of every query/word can max go upto 10
curr_count ensures that we're only counting the ones that are bigger than it
*/