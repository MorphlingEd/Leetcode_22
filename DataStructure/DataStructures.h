#ifndef LEETCODE_22_DATASTRUCTURES_H
#define LEETCODE_22_DATASTRUCTURES_H
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int>& vec){
    if (vec.empty()) return nullptr;

    int n = vec.size();
    ListNode *head = new ListNode(vec[0]), *iter = head;
    for (int i = 1; i < n; i++){
        iter->next = new ListNode(vec[i]);
        iter = iter->next;
    }

    return head;
}

void printList(ListNode* node){
    if (!node){
        cout << "null" << endl;
        return;
    }

    while(node){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

#endif //LEETCODE_22_DATASTRUCTURES_H
