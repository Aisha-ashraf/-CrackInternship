#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Main function to generate all subsets of the array
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;  // To store all subsets
        vector<int> sub;           // Temporary vector to store each subset
        subsets(nums, 0, sub, subs);
        return subs;
    }

private:
    // Helper function to generate subsets recursively
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        // Add the current subset to the result
        subs.push_back(sub);
        
        // Iterate through the nums array starting from index i
        for (int j = i; j < nums.size(); j++) {
            // Include the current element in the subset
            sub.push_back(nums[j]);
            
            // Recursively generate subsets including this element
            subsets(nums, j + 1, sub, subs);
            
            // Backtrack: remove the last element added to explore other subsets
            sub.pop_back();
        }
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Define the input
    vector<int> nums = {1, 2, 3};  // Example input
    
    // Get the result of subsets
    vector<vector<int>> result = sol.subsets(nums);
    
    // Print the result
    cout << "Subsets are:\n";
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
