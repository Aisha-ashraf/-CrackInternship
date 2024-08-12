#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; // Handle edge cases
        
        ListNode *p1 = head, *p2 = head;
        
        // Find the middle of the list
        while (p2->next != nullptr && p2->next->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode *preMiddle = p1;
        ListNode *preCurrent = p1->next;
        
        // Reverse the second half of the list
        while (preCurrent->next != nullptr) {
            ListNode *current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }
        
        // Merge the two halves
        p1 = head;
        p2 = preMiddle->next;
        
        while (p1 != preMiddle) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }
};

// Function to print the linked list
void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    ListNode *head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);
    
    Solution().reorderList(head);
    
    cout << "Reordered List: ";
    printList(head);
    
    return 0;
}
