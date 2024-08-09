#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Using a stack to reverse the list
        stack<int> st;
        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        
        // Create a new reversed list
        ListNode* reverseList = new ListNode(0); // Dummy node
        ListNode* ptr = reverseList;
        while (!st.empty()) {
            ptr->next = new ListNode(st.top());
            st.pop();
            ptr = ptr->next;
        }
        return reverseList->next; // Return the actual head of the reversed list
    }

    // Alternative approach using iterative method without extra space
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;  // Store the next node
            curr->next = prev;     // Reverse the current node's pointer
            prev = curr;           // Move the prev pointer forward
            curr = forward;        // Move the curr pointer forward
        }

        return prev; // prev is the new head of the reversed list
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the reverseList function
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    // Reverse the list using stack-based approach
    ListNode* reversedHead = solution.reverseList(head);
    cout << "Reversed list using stack: ";
    printList(reversedHead);

    // Re-create the original list to test the iterative method
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse the list using the iterative method without extra space
    ListNode* reversedHeadIterative = solution.reverseListIterative(head);
    cout << "Reversed list using iterative method: ";
    printList(reversedHeadIterative);

    return 0;
}
