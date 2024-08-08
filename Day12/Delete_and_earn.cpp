#include <iostream>
#include <vector>
#include <algorithm> // for max function

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums) {
            values[num] += num;
        }
        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {3, 4, 2};
    vector<int> nums2 = {2, 2, 3, 3, 3, 4};

    cout << "Test Case 1: " << solution.deleteAndEarn(nums1) << endl; // Output should be 6
    cout << "Test Case 2: " << solution.deleteAndEarn(nums2) << endl; // Output should be 9

    return 0;
}
