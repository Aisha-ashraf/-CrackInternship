#include <iostream>
#include <cmath>  // For pow function

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
    ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);
        int x, total = 0, i = 0;
        while (temp != nullptr) {
            x = temp->val;
            total = total + pow(2, i) * x;
            i++;
            temp = temp->next;
        }
        return total;
    }
};

int main() {
    Solution solution;

    // Test case 1: Binary number 101 (5 in decimal)
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);

    int result1 = solution.getDecimalValue(head1);
    cout << "Test case 1: " << result1 << endl; // Expected output: 5

    // Test case 2: Binary number 0 (0 in decimal)
    ListNode* head2 = new ListNode(0);

    int result2 = solution.getDecimalValue(head2);
    cout << "Test case 2: " << result2 << endl; // Expected output: 0

    // Test case 3: Binary number 1111 (15 in decimal)
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(1);
    head3->next->next = new ListNode(1);
    head3->next->next->next = new ListNode(1);

    int result3 = solution.getDecimalValue(head3);
    cout << "Test case 3: " << result3 << endl; // Expected output: 15

    // Test case 4: Binary number 10 (2 in decimal)
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(0);

    int result4 = solution.getDecimalValue(head4);
    cout << "Test case 4: " << result4 << endl; // Expected output: 2

    // Cleaning up the allocated memory
    delete head1->next->next;
    delete head1->next;
    delete head1;

    delete head2;

    delete head3->next->next->next;
    delete head3->next->next;
    delete head3->next;
    delete head3;

    delete head4->next;
    delete head4;

    return 0;
}
