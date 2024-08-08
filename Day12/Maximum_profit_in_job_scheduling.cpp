#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memset

using namespace std;

class Solution {
public:
    int n;
    int memo[50001];

    int getNextIndex(vector<vector<int>> &arr, int l, int end) {
        int r = n - 1;
        int result = n + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid][0] >= end) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& arr, int i) {
        if (i >= n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int next = getNextIndex(arr, i + 1, arr[i][1]);
        int taken = arr[i][2] + solve(arr, next);
        int notTaken = solve(arr, i + 1);
        return memo[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(memo, -1, sizeof(memo));
        vector<vector<int>> arr(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(begin(arr), end(arr));
        return solve(arr, 0);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> startTime1 = {1, 2, 3, 4};
    vector<int> endTime1 = {3, 5, 10, 6};
    vector<int> profit1 = {20, 20, 100, 70};
    
    int result1 = solution.jobScheduling(startTime1, endTime1, profit1);
    cout << "Test case 1: " << result1 << endl; // Expected output: 150
    
    // Test case 2
    vector<int> startTime2 = {1, 2, 3, 3};
    vector<int> endTime2 = {3, 4, 5, 6};
    vector<int> profit2 = {50, 10, 40, 70};
    
    int result2 = solution.jobScheduling(startTime2, endTime2, profit2);
    cout << "Test case 2: " << result2 << endl; // Expected output: 120
    
    // Test case 3
    vector<int> startTime3 = {1, 2, 3, 4, 6};
    vector<int> endTime3 = {3, 5, 10, 6, 9};
    vector<int> profit3 = {20, 20, 100, 70, 60};
    
    int result3 = solution.jobScheduling(startTime3, endTime3, profit3);
    cout << "Test case 3: " << result3 << endl; // Expected output: 150
    
    // Test case 4: No jobs
    vector<int> startTime4 = {};
    vector<int> endTime4 = {};
    vector<int> profit4 = {};
    
    int result4 = solution.jobScheduling(startTime4, endTime4, profit4);
    cout << "Test case 4: " << result4 << endl; // Expected output: 0

    return 0;
}
