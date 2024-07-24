#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Approach 2
        int position = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[position] = nums[i];
                position++;
            }
        }
        while (position < n) {
            nums[position++] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};  // Example input

    cout << "Before moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
