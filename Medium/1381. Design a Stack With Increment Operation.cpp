class CustomStack {
private:
    deque<int> stack;
    int max_size;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < max_size) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.empty()) return -1;
        int popped_el = 0;
        popped_el = stack.back();
        stack.pop_back();
        return popped_el;
    }
    
    void increment(int k, int val) {
        if(k > stack.size()) k = stack.size();
        for(int i=0; i<k; ++i) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */