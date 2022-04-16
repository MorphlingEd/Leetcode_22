#include<iostream>
#include<vector>
#include<unordered_map>
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return dp(root, memo, true);
    }

    int dp(TreeNode* node, unordered_map<TreeNode*, int>& memo, bool sign){
        if (node == nullptr)
            return 0;

        if (!sign)
            return dp(node->left, memo, true) + dp(node->right, memo, true);

        if (memo[node] != 0)
            return memo[node];

        int res =  max(node->val + dp(node->left, memo, false) + dp(node->right, memo, false),
                   dp(node->left, memo, true) + dp(node->right, memo, true));
        memo[node] = res;
        return res;
    }
};

