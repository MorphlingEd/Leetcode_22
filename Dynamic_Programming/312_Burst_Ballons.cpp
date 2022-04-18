#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n+2, vector<int> (n+2, 0));

        for (int l = 2; l <= n + 1; l++)
            for (int i = 0; i < n + 2 - l; i++){
                int j = i + l;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] +
                                   (i == 0 ? 1 : nums[i-1]) * nums[k-1] * (j == n+1 ? 1 : nums[j-1]));
            }

        return dp[0][n+1];
    }
};

//        for (int i = 0; i < n+2; i++){
//            for (int j = 0; j < n+2; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }

Solution sol;
vector<int> nums;

void testRes(){
    cout << sol.maxCoins(nums) << endl;
}

int main(){
    nums = {3,1,5,8};
    testRes();

    nums = {1,5};
    testRes();

    return 0;
}