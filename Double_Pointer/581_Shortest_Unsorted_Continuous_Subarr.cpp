#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = n, r = -1;

        stack<int> S;
        for (int i = 0; i < n; i++){
            while(!S.empty() && nums[S.top()] > nums[i]){
                l = min(l, S.top());
                S.pop();
            }
            S.push(i);
        }

        while(!S.empty())
            S.pop();

        for (int i = n-1; i >= 0; i--){
            while(!S.empty() && nums[S.top()] < nums[i]){
                r = max(r, S.top());
                S.pop();
            }
            S.push(i);
        }

        return max(0, r - l + 1);
    }

    int findUnsortedSubarrayII(vector<int>& nums) {
        int n = nums.size(), l = -1, r = -1, maxNum = INT_MIN;
        for (int i = 0; i < n; i++){
            if (maxNum > nums[i]){
                if (l == -1)
                    l = i-1;

                // The key:
                // Expanding the left boundary until the leftmost one
                // is less or equal to the rightmost
                while(l >= 1 && nums[l-1] > nums[i])
                    l--;

                // The reason why returning r-l with r = i+1 but not r - l + 1 with r = i
                // is that if the whole array is ascending, the l and r will not be updated
                r = i + 1;
            } else
                maxNum = nums[i];
        }

        return r - l;
    }

};

Solution sol;
vector<int> nums;

void testRes(){
    cout << sol.findUnsortedSubarrayII(nums) << endl;
}

int main(){
    // 5
    nums = {2,6,4,8,10,9,15};
    testRes();

    // 0
    nums = {1,2,3,4};
    testRes();

    // 0
    nums = {1};
    testRes();

    // 7
    nums = {3,6,5,1,4,7,2};
    testRes();

    // 6
    nums = {2,6,4,8,10,9,9};
    testRes();

    // 2
    nums = {2,6,4,8,9,10,10};
    testRes();

    // 6
    nums = {2,6,4,8,10,9,9,15};
    testRes();

    // 2
    nums = {1,2,4,3};
    testRes();

    // 4
    nums = {2,1,1,1};
    testRes();

    return 0;
}