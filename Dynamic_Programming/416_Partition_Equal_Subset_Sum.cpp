#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const int& i : nums)
            sum += i;

        if (sum % 2 != 0) return false;
        sum = sum / 2;

        int n = nums.size();
        vector<vector<bool>> dp (n+1, vector<bool> (sum+1, false));;

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= sum; j++){
                if (nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }

        return dp[n][sum];
    }

    bool canPartitionII(vector<int>& nums) {
        int sum = 0;
        for (const int& i : nums)
            sum += i;

        if (sum % 2 != 0) return false;
        sum = sum / 2;

        int n = nums.size();
        vector<bool> dp (sum + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++)
            for (int j = sum; j >= 1; j--)
                if (nums[i] <= j)
                    dp[j] = dp[j] || dp[j-nums[i]];

        return dp[sum];
    }

    vector<vector<vector<int>>> canPartitionIII(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        string state = "";
        vector<vector<vector<int>>> res;
        unordered_set<string> records;
        backtrack(res, state, nums, records, 0, n, sum / 2);

        return res;
    }

    void backtrack(vector<vector<vector<int>>>& res, string& state, vector<int>& nums,
                   unordered_set<string>& records, int sum, int n, int target){
        if (sum == target){
            records.insert(state);
            vector<int> part1, part2;
            for (int i = 0; i < state.size(); i++){
                if (state[i] == '0')
                    part1.push_back(nums[i]);
                else
                    part2.push_back(nums[i]);
            }

            for (int i = state.size(); i < n; i++)
                part1.push_back(nums[i]);

            res.push_back({part1, part2});
            return;
        }

        if (state.size() == n)
            return;


        int nextIdx = state.size();
        records.insert(state);


        state.push_back('0');
        if (records.find(state) == records.end())
            backtrack(res, state, nums, records, sum, n, target);
        state.pop_back();

        state.push_back('1');
        if (records.find(state) == records.end())
            backtrack(res, state, nums, records, sum + nums[nextIdx], n, target);
        state.pop_back();
    }
};

Solution sol;
vector<int> nums;

void testRes(){
    cout << (sol.canPartitionII(nums) ? "true" : "false") << endl;
}

void testResII(){
    vector<vector<vector<int>>> res = sol.canPartitionIII(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < res[i][j].size(); k++)
                cout << res[i][j][k] << " ";
            cout << endl;
        }
        cout << "------------------------------" << endl;
    }
}

int main(){
    nums = {1,5,11,5};
    testRes();
    testResII();

    nums = {1,2,3,5};
    testRes();

    nums = {1,2,5};
    testRes();

    nums = {2,1,5,3,4,5};
    testResII();

    return 0;
}