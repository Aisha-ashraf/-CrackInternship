#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;
            int remain = columnNumber % 26;
            char ch = remain + 'A';
            result.push_back(ch);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    int columnNumber;
    
    // Test cases
    cout << "Enter column number: ";
    cin >> columnNumber;
    string result = solution.convertToTitle(columnNumber);
    cout << "Column title: " << result << endl;
    
    return 0;
}
