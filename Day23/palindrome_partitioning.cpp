#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Main function to return all possible palindrome partitioning of a string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;  // To store all partitions
        vector<string> path;            // Temporary vector to store each partition
        backtrack(s, 0, path, result);
        return result;
    }

private:
    // Helper function to generate partitions using backtracking
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the result
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end) {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                // Recur to find other partitions
                backtrack(s, end, path, result);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }

    // Utility function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    
    // Define the input string
    string s = "aab";  // Example input string
    
    // Get the result of partitioning
    vector<vector<string>> result = sol.partition(s);
    
    // Print the result
    cout << "Palindrome partitions of the string \"" << s << "\" are:\n";
    for (const auto& partition : result) {
        cout << "[";
        for (size_t i = 0; i < partition.size(); ++i) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}
