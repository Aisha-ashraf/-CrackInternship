#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool palindrome(const string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return palindrome(s.substr(i, j - i)) || palindrome(s.substr(i + 1, j - i));
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "aba";
    string test2 = "abca";
    string test3 = "racecar";
    string test4 = "deeee";
    string test5 = "abc";

    cout << "Test case 1: " << (sol.validPalindrome(test1) ? "Valid Palindrome" : "Not a Valid Palindrome") << endl; // Expected output: Valid Palindrome
    cout << "Test case 2: " << (sol.validPalindrome(test2) ? "Valid Palindrome" : "Not a Valid Palindrome") << endl; // Expected output: Valid Palindrome
    cout << "Test case 3: " << (sol.validPalindrome(test3) ? "Valid Palindrome" : "Not a Valid Palindrome") << endl; // Expected output: Valid Palindrome
    cout << "Test case 4: " << (sol.validPalindrome(test4) ? "Valid Palindrome" : "Not a Valid Palindrome") << endl; // Expected output: Valid Palindrome
    cout << "Test case 5: " << (sol.validPalindrome(test5) ? "Valid Palindrome" : "Not a Valid Palindrome") << endl; // Expected output: Not a Valid Palindrome

    return 0;
}
