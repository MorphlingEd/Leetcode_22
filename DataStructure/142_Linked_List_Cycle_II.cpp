#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head->next, *fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (slow != fast)
            return nullptr;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};