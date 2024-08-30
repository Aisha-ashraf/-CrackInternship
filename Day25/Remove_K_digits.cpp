#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        string result = "";
        
        for (char digit : num) {
            // Remove characters from result while the current digit is smaller
            // and k > 0
            while (!result.empty() && result.back() > digit && k > 0) {
                result.pop_back();
                k--;
            }
            // Avoid leading zeros by not pushing '0' if result is empty
            if (!result.empty() || digit != '0') {
                result.push_back(digit);
            }
        }
        
        // If k > 0, remove the last k digits from the result
        while (!result.empty() && k > 0) {
            result.pop_back();
            k--;
        }
        
        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution solution;
    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the number of digits to remove: ";
    cin >> k;

    string result = solution.removeKdigits(num, k);
    cout << "Result after removing " << k << " digits: " << result << endl;

    return 0;
}
