#include <iostream>
#include <unordered_set>

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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createLinkedListWithCycle(int n, int pos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleNode = nullptr;
    
    for(int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(i + 1);
        
        if(i == 0) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        
        tail = newNode;
        
        if(i == pos) {
            cycleNode = newNode;
        }
    }
    
    if(tail != nullptr && cycleNode != nullptr) {
        tail->next = cycleNode;
    }
    
    return head;
}

int main() {
    Solution solution;
    
    // Test case 1: No cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    
    cout << "Test case 1: " << (solution.hasCycle(head1) ? "Cycle detected" : "No cycle") << endl;
    
    // Test case 2: Cycle at the start
    ListNode* head2 = createLinkedListWithCycle(5, 0); // 5 nodes with cycle starting at position 0
    
    cout << "Test case 2: " << (solution.hasCycle(head2) ? "Cycle detected" : "No cycle") << endl;
    
    // Test case 3: Cycle at position 2
    ListNode* head3 = createLinkedListWithCycle(5, 2); // 5 nodes with cycle starting at position 2
    
    cout << "Test case 3: " << (solution.hasCycle(head3) ? "Cycle detected" : "No cycle") << endl;

    // Clean up (delete nodes to avoid memory leaks)
    // Note: Deleting nodes for a list with a cycle requires special care. 
    // In real use cases, ensure proper memory management.
    
    return 0;
}
