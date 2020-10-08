class RandomizedSet {
private:
    unordered_map<int,int> hashmap; // maps num->index
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashmap.find(val) != hashmap.end()) return false;
        nums.push_back(val);
        hashmap[val] = nums.size()-1; // num->curr index
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashmap.find(val) == hashmap.end()) return false;
        int last = nums.back();
        hashmap[last] = hashmap[val]; //last element -> val's index
        nums[hashmap[last]] = last; //put last into ints correct position
        nums.pop_back();
        hashmap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */