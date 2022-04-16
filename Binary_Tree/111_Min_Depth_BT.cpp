#include<iostream>
#include<queue>
#include<vector>
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int depth = 0;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            depth++;
            vector<TreeNode*> layer;

            while (!Q.empty()){
                layer.push_back(Q.front());
                Q.pop();
            }

            for (TreeNode* node : layer){
                if (!node->left && !node->right)
                    return depth;

                if (node->left)  Q.push(node->left);
                if (node->right) Q.push(node->right);
            }

        }

        return depth;
    }
};