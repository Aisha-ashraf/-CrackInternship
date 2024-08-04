#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int idx = num - 1;
            if (nums[idx] < 0) {
                result.push_back(num);
            } else {
                nums[idx] *= -1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDuplicates(nums);
    
    cout << "Duplicate elements:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
