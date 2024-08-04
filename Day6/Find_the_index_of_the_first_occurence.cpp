#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        if (n == 0) return 0; // If needle is empty, return 0
        
        for (int i = 0; i <= m - n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string haystack1 = "hello";
    string needle1 = "ll";
    string haystack2 = "aaaaa";
    string needle2 = "bba";
    string haystack3 = "";
    string needle3 = "";
    string haystack4 = "mississippi";
    string needle4 = "issip";

    cout << "Test case 1: " << sol.strStr(haystack1, needle1) << endl; // Expected output: 2
    cout << "Test case 2: " << sol.strStr(haystack2, needle2) << endl; // Expected output: -1
    cout << "Test case 3: " << sol.strStr(haystack3, needle3) << endl; // Expected output: 0
    cout << "Test case 4: " << sol.strStr(haystack4, needle4) << endl; // Expected output: 4

    return 0;
}
