#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode *left = head, *right = head->next;
        while(right){
            if (right->val != left->val){
                left->next = right;
                left = left->next;
            }
            right = right->next;
        }
        left->next = nullptr;
        return head;
    }
};

Solution sol;
vector<int> vec;

void testRes(){
    ListNode* head = buildList(vec);
    ListNode* res = sol.deleteDuplicates(head);
    printList(res);
}

int main(){
    vec = {1,1,2};
    testRes();

    vec = {1,1,2,2,3,3};
    testRes();

    vec = {1};
    testRes();

    vec = {1,1};
    testRes();

    return 0;
}