#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        
        for (auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    
    // Test case
    cout << "Enter the number of strings: ";
    int size;
    cin >> size;
    
    cout << "Enter the strings: ";
    for (int i = 0; i < size; ++i) {
        string str;
        cin >> str;
        strs.push_back(str);
    }
    
    vector<vector<string>> result = solution.groupAnagrams(strs);
    
    cout << "Grouped anagrams are: " << endl;
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}
