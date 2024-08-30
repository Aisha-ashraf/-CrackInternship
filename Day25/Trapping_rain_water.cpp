#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        int ans = 0;

        // Calculate left max array
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }

        // Calculate right max array
        right[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }

        // Calculate the trapped water
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int result = solution.trap(height);
    cout << "The total amount of trapped water is: " << result << " units" << endl;

    return 0;
}
