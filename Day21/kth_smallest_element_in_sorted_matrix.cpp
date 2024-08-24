#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;  // Max-heap to store the smallest k elements
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                pq.push(matrix[i][j]);  // Push current element onto the heap
                if (pq.size() > k) {  // If the heap size exceeds k, remove the largest element
                    pq.pop();
                }
            }
        }
        return pq.top();  // The top of the heap is the k-th smallest element
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> matrix1 = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k1 = 8;
    cout << "The " << k1 << "th smallest element in the matrix is: " << solution.kthSmallest(matrix1, k1) << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {
        {1, 2},
        {1, 3}
    };
    int k2 = 2;
    cout << "The " << k2 << "th smallest element in the matrix is: " << solution.kthSmallest(matrix2, k2) << endl;

    return 0;
}
