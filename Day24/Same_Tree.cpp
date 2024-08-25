#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return (p == q);
        }
        return (p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create two binary trees
    TreeNode* p = newNode(1);
    p->left = newNode(2);
    p->right = newNode(3);

    TreeNode* q = newNode(1);
    q->left = newNode(2);
    q->right = newNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    if (result) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are not the same." << endl;
    }

    // Clean up memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
