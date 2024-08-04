#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> LeftIndex(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> RightIndex(vector<int>& arr, int n) {
        stack<int> s;
        s.push(n);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != n && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = LeftIndex(arr, n);
        vector<int> right = RightIndex(arr, n);
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = arr[i] * width;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> histogram1 = {2, 1, 5, 6, 2, 3};
    vector<int> histogram2 = {2, 4};

    cout << "Largest Rectangle Area for histogram1: " << sol.largestRectangleArea(histogram1) << endl;
    cout << "Largest Rectangle Area for histogram2: " << sol.largestRectangleArea(histogram2) << endl;

    return 0;
}
