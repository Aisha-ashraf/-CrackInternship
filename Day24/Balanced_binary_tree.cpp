#include <iostream>
#include <cmath>  // For std::abs and std::max
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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(4);

    Solution solution;
    bool result = solution.isBalanced(root);

    if (result) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up memory
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
