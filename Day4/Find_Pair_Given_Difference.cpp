#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            if (x == 0 && mp[arr[i]] > 1) {
                return 1;
            }
        }
        
        if (x == 0) {
            return -1;
        }
        
        for (int i = 0; i < n; i++) {
            int sum = x + arr[i];
            if (mp.find(sum) != mp.end()) {
                return 1;
            }
        }
        
        return -1;
    }
};

// Function to print the result
void printResult(int result) {
    if (result == -1) {
        cout << "No such pair found." << endl;
    } else {
        cout << "Pair found." << endl;
    }
}

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<int> arr1 = {1, 5, 3, 4, 2};
    int n1 = arr1.size();
    int x1 = 2;
    cout << "Input: arr = ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << ", x = " << x1 << endl;
    int result1 = solution.findPair(n1, x1, arr1);
    printResult(result1);

    // Test case 2
    vector<int> arr2 = {8, 7, 2, 5, 3, 1};
    int n2 = arr2.size();
    int x2 = 10;
    cout << "Input: arr = ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << ", x = " << x2 << endl;
    int result2 = solution.findPair(n2, x2, arr2);
    printResult(result2);

    // Test case 3
    vector<int> arr3 = {3, 5, 9, 2, 8, 10, 11};
    int n3 = arr3.size();
    int x3 = 17;
    cout << "Input: arr = ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << ", x = " << x3 << endl;
    int result3 = solution.findPair(n3, x3, arr3);
    printResult(result3);

    // Add more test cases as needed

    return 0;
}
