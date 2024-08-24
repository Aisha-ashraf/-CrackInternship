#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if placing a queen at board[row][col] is safe
    bool allowed(vector<string> &board, int row, int col, int n) {
        int r = row;
        int c = col;

        // Check the upper diagonal on the left side
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Check the left side
        r = row;
        c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        // Check the lower diagonal on the left side
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    // Backtracking function to solve the N-Queens problem
    void backtrack(int col, vector<string>& board, vector<vector<string>>& res, int n) {
        // If all queens are placed
        if (col == n) {
            res.push_back(board);
            return;
        }

        // Try placing the queen in all rows of the current column
        for (int i = 0; i < n; i++) {
            if (allowed(board, i, col, n)) {
                board[i][col] = 'Q';  // Place the queen
                backtrack(col + 1, board, res, n);  // Recur to place the rest of the queens
                board[i][col] = '.';  // Backtrack: remove the queen
            }
        }
    }

    // Function to return all possible solutions for the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;  // To store all possible solutions
        vector<string> board(n, string(n, '.'));  // Initialize the board with empty spaces
        backtrack(0, board, res, n);  // Start backtracking from the first column
        return res;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Define the size of the chessboard (N)
    int n = 4;  // Example: 4x4 chessboard

    // Get the result of solving the N-Queens problem
    vector<vector<string>> result = sol.solveNQueens(n);

    // Print the result
    cout << "All possible solutions for " << n << "-Queens are:\n";
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
