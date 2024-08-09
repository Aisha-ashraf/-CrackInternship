#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, INT_MAX);
        minCoins[0] = 0; // Base case: 0 coins are needed to make 0 amount

        if (amount < 1) {
            return 0;
        }

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && minCoins[i - coin] != INT_MAX) {
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coin]);
                }
            }
        }

        return minCoins[amount] == INT_MAX ? -1 : minCoins[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = solution.coinChange(coins, amount);
    cout << "The minimum number of coins needed: " << result << endl;

    return 0;
}
