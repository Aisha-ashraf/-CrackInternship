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
        if (!root)
            return;
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

int main() {
    // Construct the binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    // Initialize the Solution class
    Solution solution;

    // Test the kthSmallest function
    int k = 3;
    int result = solution.kthSmallest(root, k);
    cout << "The " << k << "-th smallest element in the BST is: " << result << endl;

    return 0;
}
