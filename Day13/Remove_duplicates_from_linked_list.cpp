#include <iostream>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* prev = head;
        ListNode* temp = prev->next;
        while (temp != nullptr) {
            if (temp->val == prev->val) {
                temp = temp->next;
                continue;
            }
            prev->next = temp;
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        return head;
    }
};

// Utility function to create a new ListNode
ListNode* createNode(int value) {
    return new ListNode(value);
}

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    // Test case 1: List with duplicates
    ListNode* head1 = createNode(1);
    head1->next = createNode(1);
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(3);
    head1->next->next->next->next = createNode(3);

    cout << "Original List 1: ";
    printList(head1);

    ListNode* result1 = solution.deleteDuplicates(head1);
    cout << "After removing duplicates: ";
    printList(result1);

    // Test case 2: List without duplicates
    ListNode* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);

    cout << "Original List 2: ";
    printList(head2);

    ListNode* result2 = solution.deleteDuplicates(head2);
    cout << "After removing duplicates: ";
    printList(result2);

    // Test case 3: Empty list
    ListNode* head3 = nullptr;

    cout << "Original List 3: ";
    printList(head3);

    ListNode* result3 = solution.deleteDuplicates(head3);
    cout << "After removing duplicates: ";
    printList(result3);

    // Test case 4: Single node list
    ListNode* head4 = createNode(1);

    cout << "Original List 4: ";
    printList(head4);

    ListNode* result4 = solution.deleteDuplicates(head4);
    cout << "After removing duplicates: ";
    printList(result4);

    // Clean up memory
    delete head1->next->next->next->next;
    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;

    delete head2->next->next;
    delete head2->next;
    delete head2;

    delete head4;

    return 0;
}
