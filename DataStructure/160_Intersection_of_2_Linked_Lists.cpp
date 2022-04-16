#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *iterA = headA, *iterB = headB;

        // Pay attention to the check of being null!
        // When changing the pointer to another linked list,
        // there is a 'pause' while being null.
        // If the pointers don't meet after iteration on both 2 lists,
        // they will simultaneously become null breaking the loop.
        while(iterA != iterB){
            if (!iterA) iterA = headB;
            else iterA = iterA->next;

            if (!iterB) iterB = headA;
            else iterB = iterB->next;
        }

        return iterA;
    }
};