#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s; // Stack to keep track of elements in nums2
        unordered_map<int, int> m; // Map to store the next greater element for each element in nums2
        vector<int> ans; // Result vector for the final answer

        // Traverse nums2 to fill the map with next greater elements
        for (int num : nums2) {
            // While stack is not empty and the current element is greater than the stack's top
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num; // Map the top element of the stack to the current element
                s.pop(); // Pop the stack
            }
            s.push(num); // Push the current element onto the stack
        }
        
        // For any remaining elements in the stack, there is no greater element, so map them to -1
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        // Traverse nums1 and use the map to find the next greater element
        for (int num : nums1) {
            ans.push_back(m[num]);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements for nums1: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    // Another test case
    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};

    result = solution.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements for nums1: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
