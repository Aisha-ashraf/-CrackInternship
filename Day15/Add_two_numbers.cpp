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
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0); // Dummy node to store the result
        ListNode* ptr = result; // Pointer to traverse the result list
        int carry = 0;

        // Traverse both linked lists
        while (l1 != NULL || l2 != NULL) {
            int sum = carry; // Start with the carry value

            if (l1 != NULL) {
                sum += l1->val; // Add the value from l1 if available
                l1 = l1->next; // Move to the next node in l1
            }
            if (l2 != NULL) {
                sum += l2->val; // Add the value from l2 if available
                l2 = l2->next; // Move to the next node in l2
            }

            carry = sum / 10; // Calculate the carry
            sum = sum % 10; // Get the last digit of the sum

            ptr->next = new ListNode(sum); // Create a new node for the current digit
            ptr = ptr->next; // Move the pointer to the next node
        }

        // If there's any carry left, create a new node
        if (carry == 1) {
            ptr->next = new ListNode(1);
        }

        return result->next; // Return the next of the dummy node (actual result)
    }
};

int main() {
    // Example: l1 = [2 -> 4 -> 3], l2 = [5 -> 6 -> 4]
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    while (result != NULL) {
        cout << result->val;
        if (result->next != NULL) {
            cout << " -> ";
        }
        result = result->next;
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete l1->next->next;
    delete l1->next;
    delete l1;
    delete l2->next->next;
    delete l2->next;
    delete l2;

    return 0;
}
