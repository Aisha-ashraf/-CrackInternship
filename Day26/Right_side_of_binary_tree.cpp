#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root == NULL) {
            return {};
        }
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            TreeNode* node = NULL;
            while (n--) {
                node = que.front();
                que.pop();
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
            result.push_back(node->val);
        }
        return result;
    }
};

int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Create an instance of Solution and call the rightSideView function
    Solution sol;
    vector<int> rightView = sol.rightSideView(root);

    // Print the result
    cout << "Right side view of the binary tree: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
