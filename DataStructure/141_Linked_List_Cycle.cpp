#include<iostream>
#include<vector>
#include "DataStructures.h"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *slow = head->next, *fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};

Solution sol;
vector<int> vec;

void testRes(){
    ListNode* node = buildList(vec);
    cout << (sol.hasCycle(node) ? "true" : "false") << endl;
}

int main(){
    vec = {1,2};
    testRes();

    return 0;
}