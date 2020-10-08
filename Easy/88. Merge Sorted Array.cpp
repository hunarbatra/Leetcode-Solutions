class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
        for(int i=0; i<n; ++i) {
            nums1.insert(lower_bound(nums1.begin(), nums1.end(), nums2[i]), nums2[i]);
        }
      /*  while(n)
        {
            nums1[m+n-1] = nums2[n-1];
            n--;
        }
        sort(nums1.begin(), nums1.end());
        return; */
   /*     if(!n) return;
        if(!m) { nums1 = move(nums2); return; }
        
        while(n)
        {
            if(!m || nums1[m-1] < nums2[n-1])
            {
                //if last element of nums1 is smaller than nums2 then put nums2 at last
                nums1[m+n-1] = nums2[n-1];
                n--;
            }
            else
            {
                nums1[m+n-1] = nums1[m-1];
                m--;
            }
        } */
    }
};