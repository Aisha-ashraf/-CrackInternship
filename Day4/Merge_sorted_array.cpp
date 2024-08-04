#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while (i >= 0) {
            nums1[k--] = nums1[i--];
        }
        
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    int m1 = 3;
    vector<int> nums2_1 = {2, 5, 6};
    int n1 = 3;
    cout << "Input: nums1 = ";
    printVector(nums1_1);
    cout << "m = " << m1 << ", nums2 = ";
    printVector(nums2_1);
    cout << "n = " << n1 << endl;
    solution.merge(nums1_1, m1, nums2_1, n1);
    cout << "Output: ";
    printVector(nums1_1);

    // Test case 2
    vector<int> nums1_2 = {4, 5, 6, 0, 0, 0};
    int m2 = 3;
    vector<int> nums2_2 = {1, 2, 3};
    int n2 = 3;
    cout << "Input: nums1 = ";
    printVector(nums1_2);
    cout << "m = " << m2 << ", nums2 = ";
    printVector(nums2_2);
    cout << "n = " << n2 << endl;
    solution.merge(nums1_2, m2, nums2_2, n2);
    cout << "Output: ";
    printVector(nums1_2);

    // Add more test cases as needed

    return 0;
}
