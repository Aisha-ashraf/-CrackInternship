#include <iostream>
#include <vector>
#include <numeric>  // for std::accumulate

using namespace std;

class NumArray {
public:
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(this->nums.begin() + left, this->nums.begin() + right + 1, 0);
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);

    cout << "Sum of range (0, 2): " << obj->sumRange(0, 2) << endl;  // Expected output: 1
    cout << "Sum of range (2, 5): " << obj->sumRange(2, 5) << endl;  // Expected output: -1
    cout << "Sum of range (0, 5): " << obj->sumRange(0, 5) << endl;  // Expected output: -3

    delete obj;
    return 0;
}
