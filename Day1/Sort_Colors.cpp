#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach 2: Dutch National Flag Algorithm
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = n - 1;
        
        while (j <= k) {
            if (nums[j] == 1) {
                j++;
            } else if (nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};  // Example input

    cout << "Before sorting: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.sortColors(nums);

    cout << "After sorting: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
