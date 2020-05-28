class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {

    }
    
    int get(int key) {
        auto iter = cache_.find(key);
        if (iter != cache_.end()) {
            /// move to front
            move_to_front(key);
            return (*iter).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = cache_.find(key);
        if (iter != cache_.end()) {
            /// found key, then update it
            move_to_front(key);

            cache_[key] = value;

        } else {
            if (cache_.size() >= capacity_) {
                int del_key = lru_.back();
                del_one_key(del_key);
                lru_.pop_back();
            }
            lru_.push_front(key);
            cache_[key] = value;
        }
    }
private:
    void move_to_front(int k) {
        auto found_iter = std::find(lru_.begin(), lru_.end(), k);
        if (found_iter != lru_.end() && found_iter != lru_.begin()) {
            lru_.splice(lru_.begin(), lru_, found_iter, std::next(found_iter));
        }
    }
    void del_one_key(int k) {
        auto found_iter = cache_.find(k);
        if (found_iter != cache_.end()) {
            cache_.erase(found_iter);
        }
    }
    
private:
    unordered_map<int, int> cache_;
    list<int>     lru_;
    int           capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(int argc, char *argv[]) 
{
    return 0;
}
