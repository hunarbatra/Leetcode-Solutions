class RandomizedCollection {
private:
    unordered_map<int,int> hashmap; // maps index->num
    vector<int> nums;
public:
    RandomizedCollection() {}
    bool insert(int val) {
        bool result = true;
        if(find(nums.begin(), nums.end(), val) != nums.end()) result = false;
        nums.push_back(val);
        hashmap[nums.size()-1] = val; // curr index->num
        return result;
    }
    bool remove(int val) {
        if(find(nums.begin(), nums.end(), val) == nums.end()) return false;
        int last = nums.back();
        int valpos = find(nums.begin(), nums.end(), val) - nums.begin();
        int lastpos = nums.size()-1;
        hashmap[valpos] = last;  //store last value at val's index
        hashmap.erase(lastpos); //delete the last index from hashmap
        nums[valpos] = last; //store the last value at val's index
        nums.pop_back(); //delete the last index from nums -- basically we just swapped the last element with val to be removed and deleted the last index of both nums & hashmap
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */