class MedianFinder {
private:
    priority_queue<int> firstQ; //max heap for smaller numbers
    priority_queue<int, vector<int>, greater<int>> secondQ; //min heap for larger numbers
public:
    /** initialize your data structure here. */
    MedianFinder() {} //constructor
    
    void addNum(int num) {
        if(firstQ.empty() || num<firstQ.top()) {
            firstQ.push(num);
        }
        else {
            secondQ.push(num);
        }
        
        //now lets rebalance
        if(firstQ.size() == secondQ.size()+2) {
            secondQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+2 == secondQ.size()) {
            firstQ.push(secondQ.top());
            secondQ.pop();
        }
    }
    
    double findMedian() {
        if(firstQ.size() == secondQ.size()) {
            if(firstQ.empty()) return 0;
            else return ((firstQ.top() + secondQ.top()) / 2.0 );
        }
        else if(firstQ.size()+1 == secondQ.size()) {
            return secondQ.top();
        }
        else {
            return firstQ.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */