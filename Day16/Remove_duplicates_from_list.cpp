#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);  // Create a dummy node
        ListNode* prev = dummy;  // 'prev' pointer to track the last node before duplicates
        
        while (head != NULL) {
            // Check if the current node has duplicates
            if (head->next != NULL && head->val == head->next->val) {
                // Skip all nodes that have the same value
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                // Connect 'prev' to the node after the last duplicate
                prev->next = head->next;
            } else {
                // Move 'prev' forward when there are no duplicates
                prev = prev->next;
            }
            // Move 'head' to the next node
            head = head->next;
        }
        // Return the modified list, starting from the node after dummy
        return dummy->next;
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
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    head = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
