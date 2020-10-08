class ProductOfNumbers {
private:
    vector<int> list;
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        list.push_back(num);
    }
    
    int getProduct(int k) {
        if(k > list.size()) return 0; //edge case
        int n = list.size() - 1, result = 1, i = 0;
        while(i < k) { 
            result *= list[n-i++];
        }
        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */