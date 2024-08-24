#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Fill the priority queue with the first n-k elements
        for(int i = 0; i <= n - k; i++) {
            pq.push({nums[i], i});
        }
        
        int last_ind = -1; // Keeps track of the last index added to the ans
        for(int ind = n - k + 1; ind <= n; ind++) {
            // Add the element to the priority queue
            if (ind < n) {
                pq.push({nums[ind], ind});
            }
            
            // Select the smallest valid element
            while (!pq.empty() && pq.top().second <= last_ind) {
                pq.pop();
            }
            
            // Add the smallest valid element to the answer
            ans.push_back(pq.top().first);
            last_ind = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {3, 5, 2, 6};
    int k1 = 2;
    vector<int> result1 = solution.mostCompetitive(nums1, k1);
    
    cout << "Most competitive subsequence of length " << k1 << " is: ";
    for(int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {2, 4, 3, 3, 5, 4, 9, 6};
    int k2 = 4;
    vector<int> result2 = solution.mostCompetitive(nums2, k2);
    
    cout << "Most competitive subsequence of length " << k2 << " is: ";
    for(int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
