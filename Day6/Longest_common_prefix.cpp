#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string str1 = strs.front();
        string str2 = strs.back();
        string ans = "";

        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                break;
            }
            ans += str1[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"interview", "integrate", "integral"};
    vector<string> strs4 = {"a"};
    vector<string> strs5 = {"reflower", "flow", "flight"};

    cout << "Test case 1: " << sol.longestCommonPrefix(strs1) << endl; // Expected output: "fl"
    cout << "Test case 2: " << sol.longestCommonPrefix(strs2) << endl; // Expected output: ""
    cout << "Test case 3: " << sol.longestCommonPrefix(strs3) << endl; // Expected output: "inte"
    cout << "Test case 4: " << sol.longestCommonPrefix(strs4) << endl; // Expected output: "a"
    cout << "Test case 5: " << sol.longestCommonPrefix(strs5) << endl; // Expected output: ""

    return 0;
}
