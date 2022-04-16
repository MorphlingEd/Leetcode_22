#include<iostream>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head, *prev, *curr;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = slow; curr = slow->next;
        prev->next = nullptr;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        curr = head;
        while (curr != slow){
            if (curr->val != prev->val)
                return false;
            curr = curr->next;
            prev = prev->next;
        }

        return true;
    }
};


Solution sol;
vector<int> vec;

void testRes(){
    ListNode* head = buildList(vec);
    cout << (sol.isPalindrome(head) ? "true" : "false") << endl;
}

int main(){
    vec = {1,2,2,1};
    testRes();

    vec = {1,2};
    testRes();

    vec = {1};
    testRes();

    vec = {1,2,3,2,1};
    testRes();

    vec = {1,2,3,1,1};
    testRes();

    return 0;
}