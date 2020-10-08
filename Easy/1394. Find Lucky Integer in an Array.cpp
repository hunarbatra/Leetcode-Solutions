class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.empty()) return -1;
        unordered_map<int,int> umap; //num -> freq
        int max_el = -1;
        for(int i=0; i<arr.size(); i++) {
            umap[arr[i]]++;
        }
        for(auto x : umap) {
            if(x.first == x.second) max_el = max(max_el, x.first);
        }
        return max_el;
    }
    
     int findLucky2(vector<int>& arr) { //O(n log n) + O(n) Space -> Sorting
        if(arr.empty()) return -1;
        sort(arr.begin(), arr.end());
        unordered_map<int,int> umap; //num -> freq
        for(int i=0; i<arr.size(); i++) {
            umap[arr[i]]++;
        }
        for(int i=arr.size()-1; i>=0; i--) {
            if(arr[i] == umap[arr[i]]) return arr[i];
        }
        return -1;
    }
};