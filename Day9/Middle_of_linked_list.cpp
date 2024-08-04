#include <iostream>
#include <vector> // Include the vector header

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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        if (head->next->next == nullptr)
            return head->next;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
};

// Helper function to create a linked list from an array of values
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    std::cout << "The middle node value is: " << middle->val << std::endl;

    return 0;
}
