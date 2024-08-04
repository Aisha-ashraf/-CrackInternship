#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        int rem = 0;
        mp[rem]++;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = solution.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;
    return 0;
}
