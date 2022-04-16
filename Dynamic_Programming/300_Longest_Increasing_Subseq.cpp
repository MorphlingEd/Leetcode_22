#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> dp (n, 1);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);

        for (int i = 0; i < n; i++)
            res = max(res, dp[i]);

        return res;
    }

    int lengthOfLISII(vector<int>& nums) {
        int piles = 0, n = nums.size();
        vector<int> top (n);

        for (int i = 0; i < n; i++){
            int poker = nums[i];

            int left = 0, right = piles;
            while (left < right){
                int mid = (left + right) / 2;
                if (top[mid] > poker)
                    right = mid;
                else if (top[mid] < poker)
                    left = mid + 1;
                else // putting the same poker as the top of the pile is allowed
                    right = mid;
            }

            if (left == piles)
                piles++;
            top[left] = poker;
        }

        return piles;
    }
};

Solution sol;

void testRes(vector<int>& nums){
    cout << sol.lengthOfLISII(nums) << endl;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    testRes(nums);

    nums = {0, 1, 0, 3, 2, 3};
    testRes(nums);

    nums = {7, 7, 7, 7, 7, 7};
    testRes(nums);

    return 0;
}