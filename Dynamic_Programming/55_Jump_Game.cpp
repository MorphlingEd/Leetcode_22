#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int edge = 0;

        for (int i = 0; i < n; i++){
            edge = max(edge, nums[i] + i);
            if (edge <= i) break;
        }

        return edge >= n - 1;
    }
};

Solution sol;

void testSol(vector<int>& nums){
    cout << (sol.canJump(nums) ? "True" : "False") << endl;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    testSol(nums);

    nums = {3,2,1,0,4};
    testSol(nums);

    nums = {0};
    testSol(nums);

    nums = {2, 0, 0};
    testSol(nums);

    return 0;
}