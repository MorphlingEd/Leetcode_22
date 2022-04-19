#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = -1, right = 0, maxElem = -101, n = nums.size();
        while (right < n){
            if (nums[right] > maxElem){
                maxElem = nums[right];
                nums[left+1] = nums[right];
                left++;
            }
            right++;
        }
        return left+1;
    }
};

Solution sol;
vector<int> nums;

void testRes(){
    int k = sol.removeDuplicates(nums);
    cout << "K = " << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << "\n-------------------------------------" << endl;
}

int main(){
    nums = {1,1,2};
    testRes();

    nums = {0,0,1,1,1,2,2,3,3,4};
    testRes();

    nums = {0};
    testRes();

    nums = {-1,-1,0,0,2,3,100,101,101};
    testRes();

    return 0;
}