#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> seen;  // To track if a number is already used in the arrangement
    int counter{0};     // To count the number of valid arrangements

public:
    // Backtracking function to generate valid arrangements
    void backtrack(int &N, int position) {
        if (position > N) {
            counter++;  // A valid arrangement is found
            return;
        }
        for (int i = 1; i <= N; i++) {
            // Check if the number i can be placed at the current position
            if (seen[i] || (i % position != 0 && position % i != 0)) {
                continue;  // Skip if the number i can't be placed here
            }
            seen[i] = true;  // Mark the number i as used
            backtrack(N, position + 1);  // Recur to place the next number
            seen[i] = false;  // Backtrack: unmark the number i
        }
    }

    // Function to count the number of valid arrangements
    int countArrangement(int N) {
        if (N <= 1) {
            return N;  // For N=1, there is only one valid arrangement
        }
        seen.resize(N + 1, false);  // Initialize the seen array
        backtrack(N, 1);  // Start backtracking from the first position
        return counter;  // Return the total number of valid arrangements
    }
};

int main() {
    Solution sol;

    int N = 4;  // Example: N = 4

    int result = sol.countArrangement(N);

    cout << "The number of beautiful arrangements for N = " << N << " is: " << result << endl;

    return 0;
}
