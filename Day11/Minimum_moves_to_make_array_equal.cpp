#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2]; // For odd length, take the middle element
        int steps = 0;
        for (int num : nums) {
            steps += abs(num - median);
        }
        return steps;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input
    int result = solution.minMoves2(nums);
    cout << "Minimum moves to equalize array: " << result << endl;
    return 0;
}
