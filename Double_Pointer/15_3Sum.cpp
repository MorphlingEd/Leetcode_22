#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        int lo = start, hi = nums.size()-1, sum, left, right;
        vector<vector<int>> res;
        while (lo < hi){
            left = nums[lo]; right = nums[hi];
            sum = left + right;
            if (sum == target){
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left)  lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
            else if (sum > target)
                hi--;
            else if (sum < target)
                lo++;
        }
        return res;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};

        sort(nums.begin(), nums.end());

        int n = nums.size(), target, prev = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++){
            if (nums[i] == prev) continue;
            target = -nums[i];
            vector<vector<int>> tups = twoSum(nums, target, i+1);
            for (vector<int>& tup : tups){
                tup.push_back(nums[i]);
                res.push_back(tup);
            }

            while (i < n - 2 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};

Solution sol;
vector<int> nums;

void testRes(){
    vector<vector<int>> res = sol.threeSum(nums);
    for (const vector<int>& vec : res)
        cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
    cout << "---------------" << endl;
}

int main(){
    nums = {-1,0,1,2,-1,-4};
    testRes();

    nums = {};
    testRes();

    nums = {0};
    testRes();

    nums = {0,0,0,0};
    testRes();

    return 0;
}
