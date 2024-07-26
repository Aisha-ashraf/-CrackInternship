#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;

        // Sum the first k elements
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        // Initialize maxSum with the sum of the first k elements
        int maxSum = leftSum;

        // Move from the end, replacing elements of the left part with the right part
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};

int main() {
    Solution solution;
    
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int result = solution.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;

    cardPoints = {2, 2, 2};
    k = 2;
    result = solution.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;

    cardPoints = {9, 7, 7, 9, 7, 7, 9};
    k = 7;
    result = solution.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;

    return 0;
}
