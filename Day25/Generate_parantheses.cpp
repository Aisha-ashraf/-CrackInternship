#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;

    void solve(string &curr, int open, int close, int n) {
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }
        
        if (open < n) {
            curr.push_back('(');
            solve(curr, open + 1, close, n);
            curr.pop_back();
        }
        
        if (close < open) {
            curr.push_back(')');
            solve(curr, open, close + 1, n);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        result.clear();
        string curr = "";
        solve(curr, 0, 0, n);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> parentheses = solution.generateParenthesis(n);

    cout << "All valid combinations of " << n << " pairs of parentheses are:\n";
    for (const string &str : parentheses) {
        cout << str << endl;
    }

    return 0;
}
