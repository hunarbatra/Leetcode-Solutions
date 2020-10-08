class LRUCache {
private:
    int size;
    list<int> lru; //Doubly Linked List MSU....LRU
    unordered_map<int, list<int>::iterator> mapping;
    unordered_map<int, int> keyvalue;
public:
    LRUCache(int capacity) : size(capacity) {} //constructor
    int get(int key) { 
        if(keyvalue.count(key) == 0) return -1;
        updateLRU(key);
        return keyvalue[key];
    }
    
    void put(int key, int value) { 
        if(keyvalue.size() == size && keyvalue.count(key)==0) evict();
        updateLRU(key);
        keyvalue[key] = value;
    }
    
    void updateLRU(int key) {
        if(keyvalue.count(key)) lru.erase(mapping[key]);
        lru.push_front(key);
        mapping[key] = lru.begin();
    }
    
    void evict() {
        mapping.erase(lru.back());
        keyvalue.erase(lru.back());
        lru.pop_back();
    }
};


class LRUCache1 {
private:
    int max_size;
    unordered_map<int,int> cache;
    vector<int> LRU;
public:
    LRUCache1(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) { //O(n)
        int val = -1;
        if(cache.find(key) != cache.end()) { //if key is present in our cache
            val = cache[key]; //return this value
            LRU.erase(find(LRU.begin(), LRU.end(), key)); //remove from LRU
            LRU.push_back(key); //add to recent
        }
        return val;
    }
    
    void put(int key, int value) { //O(n)
        if(cache.find(key) != cache.end()) {
            cache[key] = value; //just update the value for the key already present
            if(LRU.back()!=key) {
                LRU.erase(find(LRU.begin(), LRU.end(), key)); //remove from LRU
                LRU.push_back(key); //add to recent
            }
        } else if(LRU.size() == max_size) {
            int remove = LRU.front();
            LRU.erase(LRU.begin());
            cache.erase(remove);
            LRU.push_back(key);
            cache[key] = value;
        } else {
            LRU.push_back(key);
            cache[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */