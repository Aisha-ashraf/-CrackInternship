#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        
        // Count the frequency of each character in the string
        for (char &ch : s) {
            freq[ch - 'a']++;
        }
        
        int result = 0;
        unordered_set<int> st;
        
        // Ensure each frequency is unique by reducing duplicates
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;
                result++;
            }
            if (freq[i] > 0) {
                st.insert(freq[i]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = solution.minDeletions(s);
    cout << "Minimum deletions to make character frequencies unique: " << result << endl;

    return 0;
}
