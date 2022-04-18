#ifndef LEETCODE_22_BINARY_TREE_H
#define LEETCODE_22_BINARY_TREE_H
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrderPrint(TreeNode* root){
    if (!root) return;

    inOrderPrint(root->left);

    cout << root->val << " " << endl;

    inOrderPrint(root->right);
}

#endif //LEETCODE_22_BINARY_TREE_H
