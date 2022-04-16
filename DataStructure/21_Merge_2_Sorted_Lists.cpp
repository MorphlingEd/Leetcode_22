#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *fir = (list1->val < list2->val ? list1 : list2);
        ListNode *sec = (fir == list1 ? list2 : list1);
        ListNode *head = fir;

        // A condition always true: fir->val <= sec->val
        while (fir->next && sec){
            if (fir->val <= sec->val && sec->val < fir->next->val){
                ListNode* temp = sec->next;
                sec->next = fir->next;
                fir->next = sec;
                fir = sec;
                sec = temp;
            } else
                fir = fir->next;
        }

        // only when the first list reaches its end, concatenate
        // it with the second one
        if (!fir->next)
            fir->next = sec;

        return head;
    }
};

Solution sol;
vector<int> vec1;
vector<int> vec2;

void testRes(){
    ListNode *list1 = buildList(vec1);
    ListNode *list2 = buildList(vec2);
    ListNode *res = sol.mergeTwoLists(list1, list2);
    printList(res);
}

int main(){
    vec1 = {1,2,4};
    vec2 = {1,3,4};
    testRes();

    vec1 = {};
    vec2 = {};
    testRes();

    vec1 = {};
    vec2 = {0};
    testRes();

    vec1 = {1,2,4};
    vec2 = {3,5,6};
    testRes();

    vec1 = {1,2,3,5};
    vec2 = {2,6};
    testRes();

    vec1 = {-10,-10,-9,-4,1,2};
    vec2 = {-7};
    testRes();

    return 0;
}