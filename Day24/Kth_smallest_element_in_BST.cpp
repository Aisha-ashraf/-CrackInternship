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
    int Count = 0;
    int ans;
    
    void inOrder(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        inOrder(root->left, k);
        if (++Count == k) {
            ans = root->val;
            return;
        }
        inOrder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Helper function to delete the tree nodes
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create a binary search tree
    TreeNode* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->right = newNode(2);

    Solution solution;
    int k = 2; // Find the 2nd smallest element
    int kthSmallestValue = solution.kthSmallest(root, k);

    cout << "The " << k << "th smallest element in the BST is: " << kthSmallestValue << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}
