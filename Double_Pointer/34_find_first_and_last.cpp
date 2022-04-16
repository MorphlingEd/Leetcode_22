#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target), right_bound(nums, target)};
    }

    // To search for the left bound of the range
    int left_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] == target)
                right = mid - 1;
        }

        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] == target)
                left = mid + 1;
        }

        if (right < 0 || nums[right] != target)
            return -1;

        return right;
    }
};

void testSol(Solution& s, vector<int>& vec, int target)
{
    vector<int> sol = s.searchRange(vec, target);
    for (int i : sol)
        cout << i << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> vec = {5,7,7,8,8,10};
    testSol(s, vec, 8);
    testSol(s, vec, 6);

    vec = {};
    testSol(s, vec, 0);

    return 0;
}