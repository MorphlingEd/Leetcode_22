#include<unordered_map>
#include "Binary_Tree.h"
using namespace std;

class Solution {
public:
    TreeNode* curr;

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = new TreeNode();
        curr = res;
        inorder(root);

        return res->right;
    }

    void inorder(TreeNode *node){
        if (!node) return;

        // until the leftmost node in this subtree
        inorder(node->left);

        node->left = nullptr;
        curr->right = node;
        curr = node;

        inorder(node->right);
    }
};

Solution sol;

void testRes1(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);

    TreeNode* res = sol.increasingBST(root);
    inOrderPrint(res);
}

int main(){
    testRes1();

    return 0;
}