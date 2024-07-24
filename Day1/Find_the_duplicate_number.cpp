#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Hare and Tortoise Method
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 4, 2, 2};  // Example input

    int duplicate = solution.findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
