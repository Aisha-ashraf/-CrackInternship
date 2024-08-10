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
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has one element, it's already sorted
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL; // Cut the list into two halves

        // Recursively sort both halves
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Merge the sorted halves
        return mergeList(l1, l2);
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach any remaining elements
        if (l1 != NULL) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        // Return the merged list, skipping the dummy node
        ListNode* sortedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return sortedHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    // Print the sorted linked list
    cout << "Sorted Linked List: ";
    printList(sortedHead);

    // Clean up the dynamically allocated memory
    while (sortedHead != NULL) {
        ListNode* temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0;
}
