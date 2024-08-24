#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue (min-heap) to find the smallest element among the heads of k lists
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        // Initialize the heap with the head of each list
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        
        ListNode* dummyHead = new ListNode(0); // Dummy node to start the merged list
        ListNode* current = dummyHead;
        
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            current->next = smallest;
            current = current->next;
            
            // If the selected list has more nodes, push the next node into the heap
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }
        
        return dummyHead->next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;
    
    // Create linked lists
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};
    
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);
    ListNode* l3 = createLinkedList(list3);
    
    // Combine all lists into a vector
}
