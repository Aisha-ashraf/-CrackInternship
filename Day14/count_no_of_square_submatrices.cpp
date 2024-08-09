#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int total_sq = 0;
        
        // 1st row: add the 1-length squares
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i])
                ++total_sq;
        }
        
        // 1st col: add the 1-length squares
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0])
                ++total_sq;
        }
        
        // Start from the second row and second column
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j]) {
                    matrix[i][j] = min({matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]}) + 1;
                    total_sq += matrix[i][j];
                }
            }
        }
        
        return total_sq;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    int result = solution.countSquares(matrix);
    cout << "The total number of squares is: " << result << endl;

    return 0;
}
