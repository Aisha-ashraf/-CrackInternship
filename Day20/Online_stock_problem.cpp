#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() { }

    int next(int price) {
        int span = 1;
        
        // Calculate the span for the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the current price and its span onto the stack
        st.push({price, span});
        
        // Return the span for the current price
        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans;

    for (int price : prices) {
        spans.push_back(stockSpanner.next(price));
    }

    // Output the results
    cout << "Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    cout << "Spans:  ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}
