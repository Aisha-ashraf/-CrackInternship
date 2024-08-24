#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;
        
        // If the string length is less than k, no k duplicates can exist
        if (n < k) {
            return s;
        }
        
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1}); // Push new character with a count of 1
            } else {
                auto prev = st.top();
                st.pop();
                st.push({s[i], prev.second + 1}); // Increment the count of the top element
            }
            if (st.top().second == k) {
                st.pop(); // Remove the character if it appears k times consecutively
            }
        }

        string ans = "";
        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            while (curr.second--) {
                ans.push_back(curr.first); // Append the character to the answer string
            }
        }

        reverse(ans.begin(), ans.end()); // Reverse the string to get the correct order
        return ans;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "deeedbbcccbdaa";
    int k1 = 3;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: \"" << solution.removeDuplicates(s1, k1) << "\"" << endl;

    string s2 = "pbbcggttciiippooaais";
    int k2 = 2;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: \"" << solution.removeDuplicates(s2, k2) << "\"" << endl;

    return 0;
}
