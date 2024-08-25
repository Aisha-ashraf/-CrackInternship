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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Helper function to print the tree in in-order fashion
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
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
    // Create first binary tree
    TreeNode* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->left->left = newNode(5);

    // Create second binary tree
    TreeNode* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);
    root2->left->right = newNode(4);
    root2->right->right = newNode(7);

    Solution solution;
    TreeNode* mergedRoot = solution.mergeTrees(root1, root2);

    cout << "Inorder Traversal of the merged tree: ";
    inorderTraversal(mergedRoot);
    cout << endl;

    // Clean up memory
    deleteTree(mergedRoot);

    return 0;
}
