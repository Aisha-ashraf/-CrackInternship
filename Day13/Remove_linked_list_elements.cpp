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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head == nullptr) {
            return nullptr;
        }

        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        // Traverse the list
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Skip the node with the target value
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        // The new head is the next node of the dummy node
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
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

    // Test case: Remove elements from the list
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    cout << "Original List: ";
    printList(head);

    int valToRemove = 6;
    ListNode* result = solution.removeElements(head, valToRemove);
    cout << "List after removing " << valToRemove << ": ";
    printList(result);

    // Clean up memory
    ListNode* temp;
    while (result != nullptr) {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
