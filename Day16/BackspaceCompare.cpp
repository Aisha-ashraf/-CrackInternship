#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> p;
        
        // Process the first string
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(!st.empty()) {
                    st.pop(); // Simulate backspace by popping the top of the stack
                }
            } else {
                st.push(s[i]); // Push the character onto the stack
            }
        }
        
        // Process the second string
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '#') {
                if(!p.empty()) {
                    p.pop(); // Simulate backspace by popping the top of the stack
                }
            } else {
                p.push(t[i]); // Push the character onto the stack
            }
        }
        
        // Compare the contents of both stacks
        while(!st.empty() && !p.empty()) {
            if(st.top() != p.top()) {
                return false; // If the top elements are different, return false
            }
            st.pop();
            p.pop();
        }
        
        // Check if both stacks are empty, meaning both strings are equal
        return st.empty() && p.empty();
    }
};

int main() {
    Solution solution;
    
    string s1 = "ab#c";
    string t1 = "ad#c";
    cout << "Compare \"" << s1 << "\" with \"" << t1 << "\": " 
         << (solution.backspaceCompare(s1, t1) ? "True" : "False") << endl;
    
    string s2 = "ab##";
    string t2 = "c#d#";
    cout << "Compare \"" << s2 << "\" with \"" << t2 << "\": " 
         << (solution.backspaceCompare(s2, t2) ? "True" : "False") << endl;
    
    string s3 = "a##c";
    string t3 = "#a#c";
    cout << "Compare \"" << s3 << "\" with \"" << t3 << "\": " 
         << (solution.backspaceCompare(s3, t3) ? "True" : "False") << endl;
    
    string s4 = "a#c";
    string t4 = "b";
    cout << "Compare \"" << s4 << "\" with \"" << t4 << "\": " 
         << (solution.backspaceCompare(s4, t4) ? "True" : "False") << endl;

    return 0;
}
