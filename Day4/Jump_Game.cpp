#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxIndex) {
                return false;
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

// Function to print the result
void printResult(bool result) {
    if (result) {
        cout << "Can jump to the end." << endl;
    } else {
        cout << "Cannot jump to the end." << endl;
    }
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: nums = ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    bool result1 = solution.canJump(nums1);
    printResult(result1);

    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Input: nums = ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    bool result2 = solution.canJump(nums2);
    printResult(result2);

    // Test case 3
    vector<int> nums3 = {0};
    cout << "Input: nums = ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;
    bool result3 = solution.canJump(nums3);
    printResult(result3);

    // Add more test cases as needed

    return 0;
}
