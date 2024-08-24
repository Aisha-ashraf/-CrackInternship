#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(std::vector<int>& arr) {
        int ans = 0;
        int N = arr.size();
        std::vector<int> temp = arr;
        std::sort(temp.begin(), temp.end());
        
        for (int i = 0; i < N; i++) {
            // This is checking whether the current element is at the right place or not
            if (arr[i] != temp[i]) {
                ans++;
 
                // Swap the current element with the right index
                // so that arr[0] to arr[i] is sorted
                swap(arr, i, indexOf(arr, temp[i]));
            }
        }
        return ans;
    }

private:
    void swap(std::vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int indexOf(const std::vector<int>& arr, int ele) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == ele) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> arr = {101, 758, 315, 730, 472, 619, 460, 479};

    Solution sol;
    int result = sol.minSwaps(arr);

    std::cout << "Minimum number of swaps required: " << result << std::endl;

    return 0;
}
