#include "Binary_Tree.h"
using namespace std;

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* iter = root;
        int *n = new int();
        *n = 0;

        traverse(iter, n);

        return root;
    }

    void traverse(TreeNode *node, int *n){
        if (!node->left && !node->right){
            node->val += *n;
            *n = node->val;
            return;
        }

        if (node->right)
            traverse(node->right, n);

        node->val += *n;
        *n = node->val;

        if (node->left)
            traverse(node->left, n);
    }
};