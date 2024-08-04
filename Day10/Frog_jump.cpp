#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_index, int prevJump) {
        if (curr_stone_index == n - 1) {
            return true;
        }
        
        if (t[curr_stone_index][prevJump] != -1) {
            return t[curr_stone_index][prevJump];
        }
        
        bool result = false;
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0) {
                int next_stone = stones[curr_stone_index] + nextJump;
                if (mp.find(next_stone) != mp.end()) {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
        }
        
        return t[curr_stone_index][prevJump] = result;
    }
    
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }
        
        n = stones.size();
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(t, -1, sizeof(t));
        
        return solve(stones, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};

    cout << "Test Case 1: " << (sol.canCross(stones1) ? "Can Cross" : "Cannot Cross") << endl;
    cout << "Test Case 2: " << (sol.canCross(stones2) ? "Can Cross" : "Cannot Cross") << endl;

    return 0;
}
