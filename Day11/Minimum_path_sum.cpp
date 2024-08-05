#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& t) {
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (i == m - 1) {
            return t[i][j] = grid[i][j] + solve(grid, i, j + 1, m, n, t);
        } else if (j == n - 1) {
            return t[i][j] = grid[i][j] + solve(grid, i + 1, j, m, n, t);
        } else {
            return t[i][j] = grid[i][j] + min(solve(grid, i + 1, j, m, n, t), solve(grid, i, j + 1, m, n, t));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve(grid, 0, 0, m, n, t);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int result = solution.minPathSum(grid);
    cout << "Minimum path sum: " << result << endl;
    return 0;
}
