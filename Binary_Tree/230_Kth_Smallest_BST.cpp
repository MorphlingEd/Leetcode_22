#include "Binary_Tree.h"
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int *rank = new int(0), *res = new int(-1);
        findK(root, k, rank, res);
        return *res;
    }

    void findK(TreeNode* node, int k, int* rank, int* res){
        if (!node) return;

        findK(node->left, k, rank, res);
        if (*res >= 0) return;

        (*rank)++;
        if (*rank == k){
            *res = node->val;
            return;
        }

        findK(node->right, k, rank, res);
    }
};
