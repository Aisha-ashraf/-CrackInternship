#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> p; // Max heap to store {yi - xi, xi}
        int ans = INT_MIN;

        for (int i = 0; i < points.size(); i++) {
            // Remove points that are not within the distance k
            while (!p.empty() && (points[i][0] - p.top().second > k)) {
                p.pop();
            }

            // If the heap is not empty, calculate the potential max value
            if (!p.empty()) {
                ans = max(ans, points[i][0] + points[i][1] + p.top().first);
            }

            // Push the current point into the heap with value {yi - xi, xi}
            p.push({points[i][1] - points[i][0], points[i][0]});
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{1, 3}, {2, 0}, {3, 10}, {4, 5}};
    int k = 1;

    int maxValue = solution.findMaxValueOfEquation(points, k);
    cout << "The maximum value of the equation is: " << maxValue << endl;

    return 0;
}
