#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> dp (n+1, -1);

        for (int i = 1; i <= n; i++){
            dp[i] = max(dp[i-1] + nums[i-1] , nums[i-1]);
            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};

Solution sol;

void testSol(vector<int>& nums)
{
    cout << sol.maxSubArray(nums) << endl;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    testSol(nums);

    nums = {1};
    testSol(nums);

    nums = {5,4,-1,7,8};
    testSol(nums);

    return 0;
}