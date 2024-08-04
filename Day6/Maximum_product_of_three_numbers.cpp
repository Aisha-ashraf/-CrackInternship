#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int leftProd = nums[0] * nums[1] * nums[n - 1];
        int rightProd = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return max(leftProd, rightProd);
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {-1, -2, -3};
    vector<int> nums4 = {-1, -2, -3, -4, 5, 6};
    vector<int> nums5 = {1, -4, 3, -6, 7, 0};

    cout << "Maximum product of nums1: " << sol.maximumProduct(nums1) << endl; // Expected output: 6
    cout << "Maximum product of nums2: " << sol.maximumProduct(nums2) << endl; // Expected output: 24
    cout << "Maximum product of nums3: " << sol.maximumProduct(nums3) << endl; // Expected output: -6
    cout << "Maximum product of nums4: " << sol.maximumProduct(nums4) << endl; // Expected output: 120
    cout << "Maximum product of nums5: " << sol.maximumProduct(nums5) << endl; // Expected output: 168

    return 0;
}
