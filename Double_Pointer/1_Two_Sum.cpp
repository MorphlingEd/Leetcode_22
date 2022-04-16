#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Dummy
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, sum;

        unordered_map<int, list<int>> indices;
        for (int i = 0; i < nums.size(); i++){
            if (indices.find(nums[i]) == indices.end()){
                list<int> lis;
                lis.push_back(i);
                indices.insert(make_pair(nums[i], lis));
            }
            else
                indices[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());

        while (lo < hi){
            sum = nums[lo] + nums[hi];
            if (sum == target) {
                int left = nums[lo];
                int right = nums[hi];
                if (left == right)
                    return {indices[left].front(), indices[left].back()};
                else
                    return {indices[left].front(), indices[right].front()};
            }
            else if (sum > target)
                hi--;
            else if (sum < target)
                lo++;
        }

        return {lo, hi};
    }

    vector<int> twoSumII(vector<int>& nums, int target) {
        int toFind;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++){
            toFind = target - nums[i];
            if (indices.find(toFind) != indices.end())
                return {i, indices[toFind]};

            indices[nums[i]] = i;
        }

        return {};
    }
};

Solution sol;
vector<int> nums;
int target;

void testRes(){
    vector<int> res = sol.twoSumII(nums, target);
    cout << res[0] << " " << res[1] << endl;
}

int main(){
    nums = {2, 7, 11, 15};
    target = 9;
    testRes();

    nums = {3, 2, 4};
    target = 6;
    testRes();

    nums = {3,3};
    target = 6;
    testRes();

    nums = {3,2,4};
    target = 6;
    testRes();

    return 0;
}