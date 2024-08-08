#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            if(target[i] != arr[i]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> target1 = {1, 2, 3, 4};
    vector<int> arr1 = {2, 4, 1, 3};

    vector<int> target2 = {7, 7, 7};
    vector<int> arr2 = {7, 7, 8};

    cout << "Test Case 1: " << (solution.canBeEqual(target1, arr1) ? "True" : "False") << endl;
    cout << "Test Case 2: " << (solution.canBeEqual(target2, arr2) ? "True" : "False") << endl;

    return 0;
}
