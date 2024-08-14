#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Initialize the result vector with size n and all values 0
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example test case
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    // Get the result
    vector<int> result = solution.dailyTemperatures(temperatures);
    
    // Print the result
    cout << "Days until a warmer temperature: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
