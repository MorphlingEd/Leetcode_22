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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int in_left, int in_right,
                    int post_left, int post_right){
        if (post_left == post_right) return new TreeNode(postorder[post_left]);

        int post_root_val = postorder[post_right];
        TreeNode* root = new TreeNode(post_root_val);

        int in_root, left_size, right_size;
        for (int i = in_left; i <= in_right; i++)
            if (inorder[i] == post_root_val)
                in_root = i;

        left_size = in_root - in_left;
        right_size = in_right - in_root;

        if (left_size > 0)
            root->left = build(inorder, postorder,
                               in_left, in_root - 1,
                               post_left, post_left + left_size - 1);
        if (right_size > 0)
            root->right = build(inorder, postorder,
                                in_root + 1, in_right,
                                post_right - right_size, post_right - 1);
        return root;
    }
};