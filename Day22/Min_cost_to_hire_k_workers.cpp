#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> worker_ratio(n);

        // Calculate the wage/quality ratio for each worker and store it along with the quality
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)min_wage[worker] / quality[worker], quality[worker]);
        }

        // Sort workers based on their wage/quality ratio
        sort(worker_ratio.begin(), worker_ratio.end());

        // Max-heap to keep track of the largest qualities
        priority_queue<int> pq;
        double sum_quality = 0;
        double result = numeric_limits<double>::max();

        // Process the first 'k' workers
        for(int i = 0; i < k; i++) { 
            pq.push(worker_ratio[i].second); // Push quality into max-heap
            sum_quality += worker_ratio[i].second; // Sum of qualities
        }

        // Calculate the initial result based on the first k workers
        double managerRatio = worker_ratio[k-1].first; 
        result = managerRatio * sum_quality;

        // Iterate through the rest of the workers
        for(int manager = k; manager < n; manager++) {
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); // Push quality into max-heap
            sum_quality += worker_ratio[manager].second; // Sum of qualities

            // Ensure the heap size does not exceed k
            if(pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Calculate the minimum possible cost
            result = min(result, managerRatio * sum_quality);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> quality1 = {10, 20, 5};
    vector<int> min_wage1 = {70, 50, 30};
    int k1 = 2;
    cout << "Minimum cost to hire " << k1 << " workers: " << solution.mincostToHireWorkers(quality1, min_wage1, k1) << endl;

    // Test case 2
    vector<int> quality2 = {3, 1, 10, 10, 1};
    vector<int> min_wage2 = {4, 8, 2, 2, 7};
    int k2 = 3;
    cout << "Minimum cost to hire " << k2 << " workers: " << solution.mincostToHireWorkers(quality2, min_wage2, k2) << endl;

    return 0;
}
