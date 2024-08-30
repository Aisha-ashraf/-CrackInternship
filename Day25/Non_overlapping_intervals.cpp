#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Define a static custom comparator function for sorting
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sort by the end time of intervals
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        
        // Sort intervals using the custom comparator
        sort(intervals.begin(), intervals.end(), customComparator);

        int cnt = 1;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        
        // Return the number of intervals to remove
        return n - cnt;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int result = solution.eraseOverlapIntervals(intervals);
    cout << "Number of intervals to remove: " << result << endl;

    return 0;
}
