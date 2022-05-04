#include<iostream>
#include "Binary_Tree.h"
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return backtrack(root, LLONG_MIN, LLONG_MAX);
    }

    bool backtrack(TreeNode* node, long long lb, long long rb){
        if (!node) return true;

        if (node->val <= lb) return false;
        if (node->val >= rb) return false;

        return backtrack(node->left, lb, node->val) &&
                backtrack(node->right, node->val, rb);
    }
};

Solution sol;
TreeNode* root;

void testRes(){
    root = new TreeNode(INT_MAX);
    cout << sol.isValidBST(root) << endl;
}

int main(){
    cout << LLONG_MIN << endl;
    cout << LLONG_MAX << endl;

    testRes();

    return 0;
}