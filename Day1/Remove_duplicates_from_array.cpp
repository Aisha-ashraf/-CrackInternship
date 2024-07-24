#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Approach 2: Two pointers
        int n = nums.size();
        if (n == 0) return 0;
        
        int i = 0;
        int j = 1;
        while (j < n) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};  // Example input

    cout << "Before removing duplicates: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int newLength = solution.removeDuplicates(nums);

    cout << "After removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
