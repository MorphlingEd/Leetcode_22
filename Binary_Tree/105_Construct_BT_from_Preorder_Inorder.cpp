#include<iostream>
#include<queue>
using namespace std;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int pre_left, int pre_right, int in_left, int in_right){
        // If the range only contains one node, return this node
        if (pre_left == pre_right) return new TreeNode(preorder[pre_left]);

        // Firstly obtain the root node in the left side of preorder array
        int pre_root = preorder[pre_left], in_root, left_size, right_size;
        TreeNode* root = new TreeNode(pre_root);
        for (int i = in_left; i <= in_right; i++)
            if (inorder[i] == pre_root)
                in_root = i;

        // Left size is used to clear the range in preorder array
        // and determines whether the left subtree is needed
        left_size = in_root - in_left;
        // Right size is used only to determine whether the right subtree is needed
        right_size = in_right - in_root;

        if (left_size > 0)
            root->left = build(preorder, inorder,
                               pre_left + 1, pre_left + left_size,
                               in_left, in_root - 1);
        if (right_size > 0)
            root->right = build(preorder, inorder,
                                pre_left + left_size + 1, pre_right,
                                in_root + 1, in_right);
        return root;
    }
};