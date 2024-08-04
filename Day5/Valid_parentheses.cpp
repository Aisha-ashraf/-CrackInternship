#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &ch : s) {
            if (st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            if (ch == ')') {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (ch == '}') {
                if (st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (ch == ']') {
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test case 1: " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl; // Expected output: Valid
    cout << "Test case 2: " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl; // Expected output: Valid
    cout << "Test case 3: " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl; // Expected output: Invalid
    cout << "Test case 4: " << (sol.isValid(test4) ? "Valid" : "Invalid") << endl; // Expected output: Invalid
    cout << "Test case 5: " << (sol.isValid(test5) ? "Valid" : "Invalid") << endl; // Expected output: Valid

    return 0;
}
