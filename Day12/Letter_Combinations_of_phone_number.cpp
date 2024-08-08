#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void recur(int num, vector<string>& ans, string output, string options[]) {
        if (num == 0) {
            ans.push_back(output);
            return;
        }
        int last_dig = num % 10;
        string s1 = options[last_dig];
        for (int i = 0; i < s1.length(); i++) {
            recur(num / 10, ans, s1[i] + output, options);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.empty()) {
            return ans;
        }
        
        recur(stoi(digits), ans, output, options);
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Single digit
    string digits1 = "2";
    vector<string> result1 = solution.letterCombinations(digits1);
    cout << "Test case 1: ";
    for (string s : result1) {
        cout << s << " ";
    }
    cout << endl;

    // Test case 2: Multiple digits
    string digits2 = "23";
    vector<string> result2 = solution.letterCombinations(digits2);
    cout << "Test case 2: ";
    for (string s : result2) {
        cout << s << " ";
    }
    cout << endl;

    // Test case 3: Empty input
    string digits3 = "";
    vector<string> result3 = solution.letterCombinations(digits3);
    cout << "Test case 3: ";
    for (string s : result3) {
        cout << s << " ";
    }
    cout << endl;

    // Test case 4: Three digits
    string digits4 = "234";
    vector<string> result4 = solution.letterCombinations(digits4);
    cout << "Test case 4: ";
    for (string s : result4) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}

