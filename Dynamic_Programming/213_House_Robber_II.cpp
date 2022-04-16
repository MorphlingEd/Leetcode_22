#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        return max(robRange(nums, 0, n - 2),
                   robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>& nums, int start, int end){
        if (start == end)
            return nums[start];

        int n = end - start + 1;
        int dp = 0, dp_1 = nums[end], dp_2 = 0;

        for (int i = end - 1; i >= start; i--){
            dp = max(dp_1, nums[i] + dp_2);
            dp_2 = dp_1;
            dp_1 = dp;
        }

        return dp;
    }
};

Solution sol;

void testRes(vector<int>& nums){
    cout << sol.rob(nums) << endl;
}

int main(){
    vector<int> nums = {2, 3, 2};
    testRes(nums);

    nums = {1, 2, 3};
    testRes(nums);

    nums = {2};
    testRes(nums);

    nums = {2,3};
    testRes(nums);

    return 0;
}