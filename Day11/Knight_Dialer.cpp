#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> adj = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, 
        {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
    };

    int knightDialer(int n) {
        vector<vector<int>> dp(n, vector<int>(10, 0));
        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int nextCell : adj[j]) {
                    dp[i][nextCell] = (dp[i][nextCell] + dp[i-1][j]) % M;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 10; ++i) {
            result = (result + dp[n-1][i]) % M;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3; // Example input
    int result = solution.knightDialer(n);
    cout << "Number of distinct phone numbers of length " << n << ": " << result << endl;
    return 0;
}
