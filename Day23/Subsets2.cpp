#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to generate all unique subsets
    void solve(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int start) {
        // Add the current subset to the result
        result.push_back(temp);
        
        // Iterate through the nums array starting from 'start'
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include the current element in the subset
            temp.push_back(nums[i]);
            
            // Recursively generate subsets including this element
            solve(result, temp, nums, i + 1);
            
            // Backtrack: remove the last element added to explore other subsets
            temp.pop_back();
        }
    }

    // Main function to return all unique subsets of the array including duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> temp;            // Temporary vector to store each subset
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Start the recursive process
        solve(result, temp, nums, 0);
        
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Define the input
    vector<int> nums = {1, 2, 2};  // Example input with duplicates
    
    // Get the result of subsetsWithDup
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    
    // Print the result
    cout << "Unique subsets are:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}
