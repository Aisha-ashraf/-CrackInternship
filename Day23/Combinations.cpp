#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;  // To store all the combinations
    
    // Helper function to generate combinations
    void solve(int start, int n, int k, vector<int>& temp) {
        // If k is 0, a valid combination is found
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        
        // If start exceeds n, no more valid combinations can be formed
        if (start > n) {
            return;
        }
        
        // Include the current number and move to the next
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);
        
        // Backtrack: remove the last number added and explore other possibilities
        temp.pop_back();
        solve(start + 1, n, k, temp);
    }

    // Main function to return all combinations of k numbers out of 1 to n
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;  // Temporary vector to store each combination
        solve(1, n, k, temp);  // Start the recursive process
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Define the input
    int n = 4;  // Range from 1 to 4
    int k = 2;  // Number of elements in each combination
    
    // Get the result of combine
    vector<vector<int>> result = sol.combine(n, k);
    
    // Print the result
    cout << "Combinations of " << k << " numbers out of 1 to " << n << " are:\n";
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}
