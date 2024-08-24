#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int diff = 0;
        
        for (int i = 0; i < heights.size() - 1; i++) {
            diff = heights[i + 1] - heights[i];
            
            if (diff <= 0) {
                continue; // No resources needed if the next building is lower or the same height
            }
            
            bricks -= diff;
            pq.push(diff); // Push the height difference into the max-heap
            
            if (bricks < 0) {
                // Reclaim the largest brick usage and use a ladder instead
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if (ladders < 0) {
                // If we run out of ladders, return the last reachable building index
                return i;
            }
        }
        
        return heights.size() - 1; // If we can reach the last building, return its index
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> heights1 = {4, 2, 7, 6, 9, 14, 12};
    int bricks1 = 5;
    int ladders1 = 1;
    cout << "Furthest building that can be reached: " << solution.furthestBuilding(heights1, bricks1, ladders1) << endl;

    // Test case 2
    vector<int> heights2 = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks2 = 10;
    int ladders2 = 2;
    cout << "Furthest building that can be reached: " << solution.furthestBuilding(heights2, bricks2, ladders2) << endl;

    // Test case 3
    vector<int> heights3 = {14, 3, 19, 3};
    int bricks3 = 17;
    int ladders3 = 0;
    cout << "Furthest building that can be reached: " << solution.furthestBuilding(heights3, bricks3, ladders3) << endl;

    return 0;
}
