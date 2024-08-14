#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int arrayStartIndex = findRotation(nums);
        int index = binarySearch(nums, arrayStartIndex, nums.size() - 1, target);
        int index2 = binarySearch(nums, 0, arrayStartIndex - 1, target);
        return index == -1 ? index2 : index;
    }
    
    int findRotation(std::vector<int>& arr) {
        int N = arr.size();
        int start = 0, end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int prev = (mid - 1 + N) % N;
            int next = (mid + 1) % N;
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
                return mid;
            else if (arr[mid] >= arr[0])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return 0;
    }
    
    int binarySearch(std::vector<int>& arr, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Example test case
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    // Get the result
    int result = solution.search(nums, target);
    
    // Print the result
    if (result != -1) {
        std::cout << "Target " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}
