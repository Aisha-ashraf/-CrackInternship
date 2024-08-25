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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }

private:
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }
        if (left->val != right->val) {
            return false;
        }
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a symmetric binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);

    if (result) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
