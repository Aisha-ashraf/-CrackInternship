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
    bool inOrder(TreeNode* root, int sum, int &targetSum) {
        if (root == nullptr) {
            return false;
        }
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) { // Check if it's a leaf node
            return sum == targetSum;
        }
        return inOrder(root->left, sum, targetSum) || inOrder(root->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return inOrder(root, sum, targetSum);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a binary tree
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->right = newNode(1);

    Solution solution;
    int targetSum = 22;
    bool result = solution.hasPathSum(root, targetSum);

    if (result) {
        cout << "There is a root-to-leaf path with sum " << targetSum << "." << endl;
    } else {
        cout << "There is no root-to-leaf path with sum " << targetSum << "." << endl;
    }

    // Clean up memory
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
