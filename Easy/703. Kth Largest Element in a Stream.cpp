class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int knum;
public:
    KthLargest(int k, vector<int>& nums) {
        knum = k;
        for(int i=0; i<nums.size(); i++) {
            if(i<k) minheap.push(nums[i]); //push only k elements
            else if(i>=k && nums[i]>minheap.top()) {
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(minheap.size() < knum) { //if the heap does not have k elements
            minheap.push(val);
        }
        else if(val > minheap.top()) { 
            minheap.pop();
            minheap.push(val);
        }
        return minheap.size() == knum ? minheap.top() : -1;
    }
}; 

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */