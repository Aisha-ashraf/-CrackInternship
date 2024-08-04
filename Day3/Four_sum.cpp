#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                long long int tSum = target - (static_cast<long long int>(nums[i]) + nums[j]);
                int l = j + 1, h = n - 1;
                while (l < h) {
                    long long int sum = nums[l] + nums[h];
                    if (sum == tSum) {
                        vector<int> oneAns = {nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(oneAns);
                        while(l < h && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        while(l < h && nums[h] == nums[h - 1]) {
                            h--;
                        }
                        l++;
                        h--;
                    } else if(sum < tSum) {
                        l++;
                    } else {
                        h--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);
    
    cout << "Resulting quadruplets:" << endl;
    for (const auto& quadruplet : result) {
        cout << "[";
        for (size_t i = 0; i < quadruplet.size(); i++) {
            cout << quadruplet[i];
            if (i < quadruplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
