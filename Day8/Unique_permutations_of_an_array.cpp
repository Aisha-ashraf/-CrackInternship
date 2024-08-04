#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(unordered_map<int, int>& mp, vector<int>& temp) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second == 0) {
                continue;
            }
            temp.push_back(it->first);
            it->second--;
            solve(mp, temp);
            temp.pop_back();
            it->second++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        vector<int> temp;
        solve(mp, temp);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Test case
    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> result = solution.permuteUnique(nums);

    cout << "Unique permutations are: " << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}



