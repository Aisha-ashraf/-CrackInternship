#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Main function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    // Recursive function to solve the Sudoku puzzle using backtracking
    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    // Try placing digits 1 to 9 in the empty cell
                    for (char c = '1'; c <= '9'; c++) {
                        if (isAns(board, i, j, c)) {
                            board[i][j] = c;
                            // Recursively solve the rest of the board
                            if (solve(board)) {
                                return true;
                            } else {
                                // Backtrack if no solution is found
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no valid digit can be placed, return false
                    return false;
                }
            }
        }
        // If the entire board is filled correctly, return true
        return true;
    }

    // Function to check if placing the digit 'c' at board[row][col] is valid
    bool isAns(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the row, column, and 3x3 sub-grid
            if (board[i][col] == c || board[row][i] == c || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Define a sample Sudoku puzzle with some cells filled and others empty
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Solve the Sudoku puzzle
    sol.solveSudoku(board);

    // Print the solved Sudoku puzzle
    cout << "Solved Sudoku:\n";
    for (const auto& row : board) {
        for (const auto& c : row) {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}
