#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> l(n + 1);
        l[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                l[i] = l[i / 2] + 1;
            } else {
                l[i] = l[i / 2];
            }
        }
        return l;
    }
};

int main() {
    Solution solution;
    int n = 5;
    vector<int> result = solution.countBits(n);
    cout << "Bits count for numbers from 0 to " << n << " are: ";
    for (int i = 0; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
