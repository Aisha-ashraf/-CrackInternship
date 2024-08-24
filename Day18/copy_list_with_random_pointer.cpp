#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;

        // Step 1: Create new nodes and insert them between the original nodes
        while (curr != NULL) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers to the new nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Restore the original list and extract the copied list
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;
        while (curr != NULL) {
            curr->next = newCurr->next;
            curr = curr->next;
            if (curr != NULL) {
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }

        return newHead; // Return the head of the copied list
    }
};

// Utility function to print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        std::cout << "Value: " << curr->val;
        if (curr->random) {
            std::cout << ", Random points to: " << curr->random->val << std::endl;
        } else {
            std::cout << ", Random points to: NULL" << std::endl;
        }
        curr = curr->next;
    }
}

int main() {
    // Creating a test list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assigning random pointers
    head->random = head->next->next;        // 1 -> 3
    head->next->random = head;              // 2 -> 1
    head->next->next->random = head->next;  // 3 -> 2

    // Print the original list
    std::cout << "Original list:" << std::endl;
    printList(head);

    // Create a deep copy of the list
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // Print the copied list
    std::cout << "Copied list:" << std::endl;
    printList(copiedList);

    // Clean up memory (original list)
    delete head->next->next;
    delete head->next;
    delete head;

    // Clean up memory (copied list)
    delete copiedList->next->next;
    delete copiedList->next;
    delete copiedList;

    return 0;
}
