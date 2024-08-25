#include <iostream>
#include <vector>
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
    TreeNode* construct(int l, int r, vector<int>& nums) {
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(l, mid - 1, nums);
        root->right = construct(mid + 1, r, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        return construct(l, r, nums);
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

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;  // Delete -10
    delete root->left;        // Delete -3
    delete root->right->left; // Delete 5
    delete root->right;       // Delete 9
    delete root;              // Delete 0

    return 0;
}
