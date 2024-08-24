#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to calculate the number of unique paths considering obstacles
    int dynamicProgramming(vector<vector<int>>& obstacleGrid, int m, int n) {
        // Initialize a grid to track the number of paths
        int grid[m][n];

        // Base conditions: if the start or end is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        // Initialize the start position
        grid[0][0] = 1;

        // Fill the first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) grid[i][0] = 0;
            else grid[i][0] = grid[i-1][0];
        }

        // Fill the first row
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) grid[0][i] = 0;
            else grid[0][i] = grid[0][i-1];
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) grid[i][j] = 0;
                else grid[i][j] = grid[i][j-1] + grid[i-1][j];
            }
        }

        // Uncomment this block to print the grid (for debugging purposes)
        /*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        */

        // Return the number of unique paths to the bottom-right corner
        return grid[m-1][n-1];
    }

    // Public function to initiate the process
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return dynamicProgramming(obstacleGrid, m, n);
    }
};

int main() {
    Solution sol;

    // Example grid with obstacles
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = sol.uniquePathsWithObstacles(obstacleGrid);

    cout << "The number of unique paths is: " << result << endl;

    return 0;
}
