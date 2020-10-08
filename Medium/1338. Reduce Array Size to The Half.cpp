class Solution {
public:
    int minSetSize(vector<int>& arr) {
        if(arr.size()==0) return 0;
        unordered_map<int, int> umap; //arr[i] --> count
        for(int i=0; i<arr.size(); i++) {
            umap[arr[i]]++;
        }
        vector<int> filtered;
        for(auto it : umap) {
            filtered.push_back(it.second);
        }
        sort(filtered.begin(), filtered.end(), 
             [](int x, int y) {
                 return x > y;
        });
        int sum = 0, n = arr.size(), count = 0;;
        for(int i=0; i<filtered.size(); i++) {
            sum += filtered[i];
            count++;
            if(sum >= n/2)
                return count;
        }
        return count;
    }
};