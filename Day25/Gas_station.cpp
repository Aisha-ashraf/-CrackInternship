#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int n = gas.size();
        int remain_fuel = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            remain_fuel += gas[i] - cost[i];
            if (remain_fuel < 0) {
                ans = i + 1;
                remain_fuel = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int start = solution.canCompleteCircuit(gas, cost);
    if (start != -1) {
        cout << "The starting gas station index is: " << start << endl;
    } else {
        cout << "It is not possible to complete the circuit." << endl;
    }

    return 0;
}
