#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to find combinations
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result) {
        // If the target is negative, return as no valid combination can be formed
        if (target < 0) {
            return;
        }
        
        // If the target is zero, a valid combination is found
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        // Iterate through the candidates starting from the index `idx`
        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            // Include the current candidate in the combination
            curr.push_back(candidates[i]);
            
            // Recursively find the next candidate with reduced target and incremented index
            solve(candidates, target - candidates[i], curr, i + 1, result);
            
            // Backtrack by removing the last candidate added to the combination
            curr.pop_back();
        }
    }

    // Main function to return all unique combinations that sum to target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;  // To store the final result
        vector<int> curr;            // To store the current combination
        
        // Sort candidates to handle duplicates easily
        sort(candidates.begin(), candidates.end());
        
        // Start finding combinations from index 0
        solve(candidates, target, curr, 0, result);
        
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Define the input
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    // Get the result of combinationSum2
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    
    // Print the result
    cout << "Combinations that sum to " << target << " are:\n";
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
