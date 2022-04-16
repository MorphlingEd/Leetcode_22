#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        vector<int> dp (n+1, 0);
        dp[n-1] = nums[n-1];

        for (int i = n - 2; i >= 0; i--)
            dp[i] = max(nums[i] + dp[i+2],
                        dp[i+1]);
        return dp[0];
    }

    int robII(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        int dp_1 = nums[n-1], dp_2 = 0, dp = 0;

        for (int i = n - 2; i >= 0; i--){
            dp = max(dp_1, nums[i] + dp_2);
            dp_2 = dp_1;
            dp_1 = dp;
        }

        return dp;
    }
};

Solution sol;

void testSol(vector<int>& nums){
    cout << sol.rob(nums) << endl;
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    testSol(nums);

    nums = {2, 7, 9, 3, 1};
    testSol(nums);

    nums = {2, 7};
    testSol(nums);

    nums = {10};
    testSol(nums);

    nums = {2, 1, 1, 2};
    testSol(nums);

    return 0;
}

