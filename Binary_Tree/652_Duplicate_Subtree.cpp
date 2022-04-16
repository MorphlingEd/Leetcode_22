#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
#include "Binary_Tree.h"
using namespace std;

class Solution {
public:

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) return {};

        vector<TreeNode*> res;
        unordered_map<string, int> record;

        traverse(res, record, root);

        return res;
    }

    string traverse(vector<TreeNode*>& res, unordered_map<string, int>& record, TreeNode* node){
        if (!node)
            return "#";

        string subtree;
        subtree = to_string(node->val) +
                    "," + traverse(res, record, node->left) +
                    "," + traverse(res, record, node->right);

        if (record[subtree] == 1)
            res.push_back(node);

        record[subtree]++;
        return subtree;
    }
};