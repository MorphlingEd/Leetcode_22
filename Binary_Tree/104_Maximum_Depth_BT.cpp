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
    int depth = 0;
    int res = 0;

    int maxDepth_Backtracing(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root){
        if (root == nullptr)
            return;

        depth++;
        res = max(res, depth);

        traverse(root->left);
        traverse(root->right);

        depth--;
    }

    int maxDepth_DFS(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftMax = maxDepth_DFS(root->left);
        int rightMax = maxDepth_DFS(root->right);

        return 1 + max(leftMax, rightMax);
    }
};

