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
    // Function to get the length of a linked list
    int getListLength(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        // Traverse the linked list and count nodes
        while (temp != NULL) {
            temp = temp->next;
            cnt++; // Increment cnt for every node traversed
        }
        return cnt;
    }

    // Function to get the intersection node of two linked lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);

        // Align the starting point for both linked lists
        while (lenA > lenB) {
            lenA--;
            headA = headA->next;
        }
        while (lenB > lenA) {
            lenB--;
            headB = headB->next;
        }

        // Move in sync to find the intersection point
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

int main() {
    // Create two linked lists with an intersection
    // Example: List A = 4 -> 1 -> 8 -> 4 -> 5
    //          List B = 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    Solution solution;
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    if (intersectionNode != NULL) {
        cout << "The intersection node's value is: " << intersectionNode->val << endl;
    } else {
        cout << "There is no intersection." << endl;
    }

    // Clean up dynamically allocated memory
    delete headA->next->next->next; // intersect->next->next
    delete headA->next->next;       // intersect->next
    delete intersect;               // intersect
    delete headA->next;             // headA->next
    delete headA;                   // headA
    delete headB->next->next->next; // headB->next->next->next
    delete headB->next->next;       // headB->next->next
    delete headB->next;             // headB->next
    delete headB;                   // headB

    return 0;
}
