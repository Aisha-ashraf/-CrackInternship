#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            bool found = backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                         backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1);
            
            board[i][j] = temp; 
            return found;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Function to print a 2D board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    cout << "Input: board = " << endl;
    printBoard(board1);
    cout << "word = " << word1 << endl;
    bool result1 = solution.exist(board1, word1);
    cout << "Output: " << (result1 ? "true" : "false") << endl;

    // Test case 2
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "SEE";
    cout << "Input: board = " << endl;
    printBoard(board2);
    cout << "word = " << word2 << endl;
    bool result2 = solution.exist(board2, word2);
    cout << "Output: " << (result2 ? "true" : "false") << endl;

    // Test case 3
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word3 = "ABCB";
    cout << "Input: board = " << endl;
    printBoard(board3);
    cout << "word = " << word3 << endl;
    bool result3 = solution.exist(board3, word3);
    cout << "Output: " << (result3 ? "true" : "false") << endl;

    // Add more test cases as needed

    return 0;
}
