#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prefix = 1, suffix = 1;
        double ans = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix = nums[i] * prefix;
            suffix = nums[n - i - 1] * suffix;
            ans = max(ans, max(prefix, suffix));
        }
        
        return static_cast<int>(ans);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4}; // Example input
    cout << "Maximum product subarray: " << solution.maxProduct(nums) << endl;
    return 0;
}
