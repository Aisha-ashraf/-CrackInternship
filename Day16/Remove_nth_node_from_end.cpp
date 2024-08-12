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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* firstptr = dummy;
        ListNode* secondPtr = dummy;

        // Move secondPtr n steps ahead
        for (int i = 0; i < n; i++) {
            secondPtr = secondPtr->next;
        }

        // Move both pointers until secondPtr reaches the end
        while (secondPtr->next != NULL) {
            firstptr = firstptr->next;
            secondPtr = secondPtr->next;
        }

        // Remove the nth node from the end
        firstptr->next = firstptr->next->next;

        // Return the new head
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
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    int n = 2; // Remove the 2nd node from the end
    Solution solution;
    head = solution.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
