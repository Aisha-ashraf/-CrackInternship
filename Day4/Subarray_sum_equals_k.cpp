#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int result = 0; 
        int curSum = 0;
        mp.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (mp.find(curSum - k) != mp.end()) {
                result += mp[curSum - k];
            }
            mp[curSum]++;
        }
        return result;
    }
};

// Function to print a vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "Input: nums = ";
    printVector(nums1);
    cout << "k = " << k1 << endl;
    int result1 = solution.subarraySum(nums1, k1);
    cout << "Output: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Input: nums = ";
    printVector(nums2);
    cout << "k = " << k2 << endl;
    int result2 = solution.subarraySum(nums2, k2);
    cout << "Output: " << result2 << endl;

    // Add more test cases as needed

    return 0;
}
