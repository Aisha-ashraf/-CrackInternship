#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token);
            }
        }
        
        if (st.empty()) {
            return "/";
        }
        
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string path1 = "/home/";
    string path2 = "/../";
    string path3 = "/home//foo/";
    string path4 = "/a/./b/../../c/";
    string path5 = "/a/../../b/../c//.//";

    cout << "Simplify path1: " << sol.simplifyPath(path1) << endl; // Expected output: "/home"
    cout << "Simplify path2: " << sol.simplifyPath(path2) << endl; // Expected output: "/"
    cout << "Simplify path3: " << sol.simplifyPath(path3) << endl; // Expected output: "/home/foo"
    cout << "Simplify path4: " << sol.simplifyPath(path4) << endl; // Expected output: "/c"
    cout << "Simplify path5: " << sol.simplifyPath(path5) << endl; // Expected output: "/c"

    return 0;
}
