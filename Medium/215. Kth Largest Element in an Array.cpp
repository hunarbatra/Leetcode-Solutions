class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        priority_queue<int> maxheap;
        for(int i=0; i<nums.size(); i++) {
            maxheap.push(nums[i]);
        }
        while(--k) {
            maxheap.pop();
        }
        return maxheap.top();
    }
};
//Solution #1 using MinHeap
    int findKthLargestminheap(vector<int>& nums, int k) {
        if(nums.empty() || k > nums.size()) return 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i=0; i<nums.size(); i++) {
            if(minheap.size() < k) {
                minheap.push(nums[i]);
            }
            else if(nums[i] > minheap.top()) {
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();
    }
}; 

/*
At any point, the minheap is only going to have k elements in it
So, the space complexity comes out to be - O(k)
Time complexity - O(n log k) -> because at worse we might have to push n elements if the array is already sorted
*/