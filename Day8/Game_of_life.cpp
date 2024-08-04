#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidNeighbour(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
        vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int count_live_neighbours = 0;
                for (int i = 0; i < 8; i++) {
                    int curr_x = row + dx[i];
                    int curr_y = col + dy[i];
                    if (isValidNeighbour(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1) {
                        count_live_neighbours++;
                    }
                }

                if (board[row][col] == 1 && (count_live_neighbours < 2 || count_live_neighbours > 3)) {
                    board[row][col] = -1;  // Mark as to be dead
                }
                if (board[row][col] == 0 && count_live_neighbours == 3) {
                    board[row][col] = 2;   // Mark as to be alive
                }
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Initial board:" << endl;
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    sol.gameOfLife(board);

    cout << "Board after running gameOfLife:" << endl;
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
