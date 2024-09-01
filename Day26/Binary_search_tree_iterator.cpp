#include <iostream>
#include <stack>

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

class BSTIterator {
private:
    stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            node = node->left;
        }
    }
};

int main() {
    // Creating a sample binary search tree:
    //        7
    //       / \
    //      3   15
    //         /  \
    //        9    20
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Create an instance of BSTIterator
    BSTIterator* iterator = new BSTIterator(root);

    // Demonstrate the usage of the BSTIterator
    cout << "BSTIterator traversal: ";
    while (iterator->hasNext()) {
        cout << iterator->next() << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete iterator;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
