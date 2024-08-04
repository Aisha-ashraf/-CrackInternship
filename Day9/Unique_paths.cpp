#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int m = 3; // Example input for rows
    int n = 7; // Example input for columns
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << solution.uniquePaths(m, n) << endl;
    return 0;
}
