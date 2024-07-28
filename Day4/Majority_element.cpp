#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (nums[i] == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        if (cnt1 > nums.size() / 2) {
            return el;
        }
        return -1;
    }
};

// Function to print the result
void printResult(int result) {
    if (result == -1) {
        cout << "No majority element found." << endl;
    } else {
        cout << "Majority element: " << result << endl;
    }
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Input: nums = ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    int result1 = solution.majorityElement(nums1);
    printResult(result1);

    // Test case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Input: nums = ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    int result2 = solution.majorityElement(nums2);
    printResult(result2);

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Input: nums = ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;
    int result3 = solution.majorityElement(nums3);
    printResult(result3);

    // Add more test cases as needed

    return 0;
}
