#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int i = 0, l = 0, r = 0, n = s.length();
        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r] = s[i];
                i++;
                r++;
            }
            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }

        // Remove the trailing space
        s = s.substr(0, r - 1);
        return s;
    }
};

int main() {
    Solution sol;
    string str1 = "the sky is blue";
    string str2 = "  hello world  ";
    string str3 = "a good   example";

    cout << "Original: \"" << str1 << "\" | Reversed: \"" << sol.reverseWords(str1) << "\"" << endl;
    cout << "Original: \"" << str2 << "\" | Reversed: \"" << sol.reverseWords(str2) << "\"" << endl;
    cout << "Original: \"" << str3 << "\" | Reversed: \"" << sol.reverseWords(str3) << "\"" << endl;

    return 0;
}
