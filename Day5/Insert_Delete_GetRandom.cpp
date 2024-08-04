#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <sstream>

using namespace std;



// RandomizedSet class
class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int idx = mp[val];
        int last = vec.back();
        vec[idx] = last;
        mp[last] = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        srand(time(0));
        int idx = rand() % vec.size();
        return vec[idx];
    }
};

int main() {


    // Test RandomizedSet class
    RandomizedSet randomizedSet;
    cout << (randomizedSet.insert(1) ? "Inserted 1" : "Failed to insert 1") << endl; // Inserts 1
    cout << (randomizedSet.remove(2) ? "Removed 2" : "Failed to remove 2") << endl; // Fails to remove 2, not present
    cout << (randomizedSet.insert(2) ? "Inserted 2" : "Failed to insert 2") << endl; // Inserts 2
    cout << "Random element: " << randomizedSet.getRandom() << endl; // Should return 1 or 2
    cout << (randomizedSet.remove(1) ? "Removed 1" : "Failed to remove 1") << endl; // Removes 1
    cout << (randomizedSet.insert(2) ? "Inserted 2" : "Failed to insert 2") << endl; // Fails to insert 2, already present
    cout << "Random element: " << randomizedSet.getRandom() << endl; // Should return 2

    return 0;
}
