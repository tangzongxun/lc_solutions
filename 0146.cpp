struct CacheElem {
    int value;
    list<int>::iterator pos;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        current_amount_ = 0;
    }
    
    int get(int key) {
        auto iter = hash_map_.find(key);
        if (iter == hash_map_.end()) {
            return -1;
        }
        // Update cached list
        cached_.push_front(key);
        auto new_pos = cached_.begin();
        cached_.erase(iter->second.pos);
        iter->second.pos = new_pos;
        return iter->second.value;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            current_amount_++;
            if (current_amount_ > capacity_) {
                auto deleted_key = cached_.back();
                cached_.pop_back();
                hash_map_.erase(hash_map_.find(deleted_key));
                current_amount_--;
            }
            cached_.push_front(key);
            hash_map_[key] = CacheElem{value, cached_.begin()};
            return;
        }
        hash_map_[key].value = value;
    }
private:
    int capacity_;
    int current_amount_;
    unordered_map<int, CacheElem> hash_map_;
    list<int> cached_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
