#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, n);
        dp[n-1] = 0;

        for (int p = n - 2; p >= 0; p--)
            for (int j = 1; j <= nums[p]; j++){
                if (p + j >= n)
                    break;
                dp[p] = min(dp[p], dp[p + j] + 1);
            }

        return dp[0];
    }

    int jumpII(vector<int>& nums) {
        int n = nums.size();

        // end is the range that can be reached from the current index
        // jumps records the number of steps needed to reach current index
        int end = 0, edge = 0, jumps = 0;

        for (int i = 0; i < n - 1; i++)
        {
            edge = max(edge, i + nums[i]);
            if (i == end){
                jumps++;
                end = edge;
                if (edge >= n-1)
                    break;
            }
        }

        return jumps;
    }


};

Solution sol;

void testSol(vector<int>& nums){
    cout << sol.jump(nums) << endl;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    testSol(nums);

    nums = {2, 3, 0, 1, 4};
    testSol(nums);

    nums = {2, 0, 0};
    testSol(nums);

    nums = {0};
    testSol(nums);

    nums = {1, 0};
    testSol(nums);

    return 0;
}