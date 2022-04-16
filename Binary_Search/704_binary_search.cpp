#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }

        return -1;
    }
};

Solution s;

void testSol(vector<int>& vec, int target)
{
    cout << s.search(vec, target) << endl;
}

int main()
{
    vector<int> vec = {-1,0,3,5,9,12};
    int target = 9;
    testSol(vec, target);

    target = 2;
    testSol(vec, target);

    vec = {2}; target = 10;
    testSol(vec, target);

    return 0;
}