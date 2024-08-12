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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* LeftPre = dummy;
        ListNode* currNode = head;

        // Move to the node before the 'left' position
        for (int i = 0; i < left - 1; i++) {
            LeftPre = LeftPre->next;
            currNode = currNode->next;
        }

        // Reverse the sublist from 'left' to 'right'
        ListNode* subList = currNode;
        ListNode* preNode = NULL;
        for (int i = 0; i <= right - left; i++) {
            ListNode* nextNode = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = nextNode;
        }

        // Connect the reversed sublist with the rest of the list
        LeftPre->next = preNode;
        subList->next = currNode;

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

    int left = 2, right = 4;
    Solution solution;
    head = solution.reverseBetween(head, left, right);

    cout << "List after reversing between position " << left << " and " << right << ": ";
    printList(head);

    return 0;
}
