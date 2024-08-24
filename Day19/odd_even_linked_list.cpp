#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Store the head of even-indexed nodes

        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        
        odd->next = evenHead;  // Connect the odd list with the even list
        return head;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Utility function to free a linked list
void freeList(ListNode* &head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;  // Deallocate memory
    }
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Create Solution object
    Solution sol;

    // Rearrange the list
    ListNode* result = sol.oddEvenList(head);

    // Print the rearranged list
    std::cout << "Rearranged list: ";
    printList(result);

    // Free the list
    freeList(result);

    return 0;
}
