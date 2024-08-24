#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        int count = -1;
        int fresh = 0;
        queue<pair<int, int>> q;

        // Count fresh oranges and push rotten ones to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // BFS to spread the rot
        while (!q.empty()) {
            int qs = q.size();
            while (qs--) {
                pair<int, int> p = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int i1 = p.first + dir[0];
                    int j1 = p.second + dir[1];
                    if ((i1 >= 0 && i1 < m) && (j1 >= 0 && j1 < n) && grid[i1][j1] == 1) {
                        grid[i1][j1] = 2;
                        q.push({i1, j1});
                        fresh--;
                    }
                }
            }
            count++;
        }

        if (fresh > 0) return -1;
        if (count == -1) return 0;
        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = solution.orangesRotting(grid);

    cout << "Minimum number of minutes until no fresh orange remains: " << result << endl;

    return 0;
}
