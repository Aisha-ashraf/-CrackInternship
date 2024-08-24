#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> m;
        unordered_map<long long, int> map;
        m.push(1);
        
        long long temp;
        while (n > 0) {
            temp = m.top();
            m.pop();
            
            if (map[temp] == 0) {
                m.push(temp * 2);
                m.push(temp * 3);
                m.push(temp * 5);
                map[temp] = 1;
                n--;
            }
        }

        return static_cast<int>(temp);
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 10;
    cout << "The " << n1 << "th ugly number is: " << solution.nthUglyNumber(n1) << endl;

    // Test case 2
    int n2 = 15;
    cout << "The " << n2 << "th ugly number is: " << solution.nthUglyNumber(n2) << endl;

    return 0;
}
