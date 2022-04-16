#include<iostream>
#include<vector>
#include<queue>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int k = lists.size();
        ListNode *res = new ListNode(), *iter = res;
        auto cmp = [](const ListNode* node1, const ListNode* node2){
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < k; i++)
            if (lists[i])
                pq.push(lists[i]);

        while(!pq.empty()){
            ListNode *node = pq.top(); pq.pop();

            iter->next = new ListNode(node->val);
            iter = iter->next;

            if (node->next) pq.push(node->next);
        }

        return res->next;
    }
};

Solution sol;
vector<vector<int>> vecs;

void testRes(){
    int n = vecs.size();
    vector<ListNode*> lists (n);
    ListNode* res;
    for (int i = 0; i < n; i++)
        lists[i] = buildList(vecs[i]);

    res = sol.mergeKLists(lists);
    printList(res);
}

int main(){
    vecs = {{1,4,5},
            {1,3,4},
            {2,6}};
    testRes();

    vecs = {};
    testRes();

    vecs = {{}};
    testRes();

    return 0;
}