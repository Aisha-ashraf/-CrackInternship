#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool subsetSum(vector<int>& nums, int n, int sum, vector<vector<int>> &dp) {
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        if (nums[n-1] <= sum) {
            return dp[n][sum] = subsetSum(nums, n-1, sum-nums[n-1], dp) || subsetSum(nums, n-1, sum, dp);
        } else {
            return dp[n][sum] = subsetSum(nums, n-1, sum, dp);
        }
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        for (int i = 0; i <= sum; i++) {
            dp[0][i] = false;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        return subsetSum(nums, n, sum, dp);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5}; // Example input

    if (solution.canPartition(nums)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
