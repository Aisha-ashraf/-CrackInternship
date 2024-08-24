#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        // Custom comparator for the min-heap
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        };
        
        // Min-heap to keep the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minh(comp);

        // Count the frequency of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Keep only the top k elements in the min-heap
        for (auto& it : mp) {
            minh.push({it.second, it.first});
            if (minh.size() > k) {
                minh.pop();
            }
        }

        // Extract the elements from the min-heap
        while (!minh.empty()) {
            ans.push_back(minh.top().second);
            minh.pop();
        }

        // The result may be in reverse order since it's from a min-heap
      //  reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);
    cout << "Top " << k1 << " frequent elements in [1, 1, 1, 2, 2, 3]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = solution.topKFrequent(nums2, k2);
    cout << "Top " << k2 << " frequent element in [1]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
