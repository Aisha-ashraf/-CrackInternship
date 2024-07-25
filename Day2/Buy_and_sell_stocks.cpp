#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int buy_price = prices[0];
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy_price) {
                buy_price = prices[i];
            } else {
                int currProfit = prices[i] - buy_price;
                profit = max(currProfit, profit);
            }
        }
        
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
