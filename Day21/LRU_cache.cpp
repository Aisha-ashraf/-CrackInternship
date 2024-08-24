#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
    
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if (map_.find(key) != map_.end()) { // key exists in the map
            list_.splice(list_.begin(), list_, map_[key]); // Move accessed item to front
            return map_[key]->second;
        }
        return -1; // key does not exist
    }
    
    void put(int key, int value) {
        if (map_.find(key) != map_.end()) { // key exists in the map
            map_[key]->second = value;
            list_.splice(list_.begin(), list_, map_[key]); // Move updated item to front
            return;
        }

        list_.push_front(make_pair(key, value)); // Insert new key-value pair at front
        map_[key] = list_.begin(); // Update map with new key's position

        if (list_.size() > capacity_) { // Check if capacity exceeded
            auto& back = list_.back(); // Get the least recently used item (back of the list)
            map_.erase(back.first); // Remove it from the map
            list_.pop_back(); // Remove it from the list
        }
    }
};

int main() {
    LRUCache cache(2); // Cache capacity of 2

    // Perform cache operations and print the results
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl; // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 3
    cout << "Get 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
