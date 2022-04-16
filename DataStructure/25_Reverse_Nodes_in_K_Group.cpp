#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode *prev = head, *curr = head->next, *tail = head, *nextP;

        int c = 1;
        while (tail->next && c < k){
            tail = tail->next;
            c++;
        }
        if (c < k) return head;

        nextP = tail->next;
        while(curr != nextP){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head->next = reverseKGroup(nextP, k);
        return tail;
    }
};

Solution sol;
vector<int> vec;
ListNode* head;
int k;

void testRes(){
    ListNode* res = sol.reverseKGroup(head, k);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}

int main(){
    vec = {1,2,3,4,5};
    head = buildList(vec);
    k = 2;
    testRes();


    head = buildList(vec);
    k = 3;
    testRes();

    return 0;
}