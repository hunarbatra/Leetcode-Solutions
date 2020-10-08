class Solution {
public:
    int singleNumber(vector<int>& nums) {
       //lets use XOR
       /* int x = 0;
        for(int i=0;i<nums.size();i++)
        {
            x = x ^ nums[i];
        }
        return x; */
        unordered_map<int,int> umap;
        for(auto i=0;i<nums.size();i++) {
            umap[nums[i]]++;
        }
        for(auto count : umap) {
            if(count.second!=2)
                return count.first;
        }
        return 0;
    }
};