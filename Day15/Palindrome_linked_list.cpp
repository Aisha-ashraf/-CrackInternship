#include <iostream>
#include <stack>

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
    // Function to reverse the second half of the linked list
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        while (head != NULL) {
            st.push(head->val);
            head = head->next;
        }
        ListNode* reverseList = new ListNode(0);
        ListNode* ptr = reverseList;
        while (!st.empty()) {
            ptr->next = new ListNode(st.top());
            st.pop();
            ptr = ptr->next;
        }
        return reverseList->next;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        
        // Finding the middle of the linked list
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // If the list has an odd number of elements, move slow one step further
        if (fast != NULL) {
            slow = slow->next;
        }

        // Reverse the second half of the list
        slow = reverseList(slow);
        fast = head;

        // Compare the first half with the reversed second half
        while (slow != NULL) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;

    // Check if the linked list is a palindrome
    if (solution.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
