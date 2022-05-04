#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Prefix Sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, iterSum = 0;
        unordered_map<int,int> preSum;
        preSum[0] = 1;

        for (int i = 0; i < n; i++){
            iterSum += nums[i];
            if (preSum.find(iterSum - k) != preSum.end())
                ans += preSum[iterSum-k];

            preSum[iterSum]++;
        }

        return ans;
    }
};

Solution sol;
vector<int> nums;
int k;

void testRes(){
    cout << sol.subarraySum(nums, k) << endl;
}

int main(){
    nums = {1,1,1};
    k = 2;
    testRes();

    nums = {1,2,3};
    k = 3;
    testRes();

    nums = {1};
    k = 2;
    testRes();

    k = 1;
    testRes();

    nums = {2,-2,2,-1,-1};
    k = 0;
    testRes();

    return 0;
}