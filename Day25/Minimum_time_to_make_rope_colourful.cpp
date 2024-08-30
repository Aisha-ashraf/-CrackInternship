#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int prevMax = 0;

        for (int i = 0; i < n; i++) {
            // If the current balloon color is different from the previous one, reset prevMax
            if (i > 0 && colors[i] != colors[i - 1]) {
                prevMax = 0;
            }
            int curr = neededTime[i];
            // Add the smaller of prevMax or curr to the time
            time += min(prevMax, curr);
            // Update prevMax to be the maximum of itself and curr
            prevMax = max(prevMax, curr);
        }

        return time;
    }
};

int main() {
    Solution solution;
    string colors;
    vector<int> neededTime;

    // Example input
    cout << "Enter the string of balloon colors: ";
    cin >> colors;

    int n = colors.size();
    neededTime.resize(n);
    cout << "Enter the time needed to remove each balloon (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> neededTime[i];
    }

    int result = solution.minCost(colors, neededTime);
    cout << "Minimum time to make the rope colorful: " << result << endl;

    return 0;
}
