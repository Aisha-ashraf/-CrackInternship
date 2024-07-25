#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        // Two-pointer approach (requires sorting)
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end());
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int sum = v[s].first + v[e].first;
            if (sum == target) {
                return {v[s].second, v[e].second};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return {-1, -1};
        */

        // Hashmap approach
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int remain = target - nums[i];
            if (mp.find(remain) != mp.end()) {
                return {mp[remain], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    return 0;
}
