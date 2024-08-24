#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        
        // Count the frequency of each character in the string
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        
        // Max-heap to store characters by frequency
        priority_queue<pair<int, char>> pq;
        
        // Push all characters with their frequencies into the heap
        for (auto itr : mp) {
            pq.push(make_pair(itr.second, itr.first));
        }
        
        // Variable to store the previous character and its frequency
        pair<int, char> g = {-1, '$'};
        string ans = "";
        
        // Reorganize the string
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            ans += temp.second;
            temp.first--;
            
            // Push the previous character back into the heap if it still has remaining frequency
            if (g.first > 0) {
                pq.push(g);
            }
            
            g = temp; // Update the previous character
        }
        
        // Check if the reorganized string is valid (i.e., has the same length as the original string)
        if (s.size() == ans.size()) {
            return ans;
        }
        
        // If not possible to reorganize, return an empty string
        return "";
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "aab";
    string result1 = solution.reorganizeString(s1);
    cout << "Reorganized string for '" << s1 << "': " << result1 << endl;

    // Test case 2
    string s2 = "aaab";
    string result2 = solution.reorganizeString(s2);
    cout << "Reorganized string for '" << s2 << "': " << result2 << endl;

    // Test case 3
    string s3 = "vvvlo";
    string result3 = solution.reorganizeString(s3);
    cout << "Reorganized string for '" << s3 << "': " << result3 << endl;

    return 0;
}
