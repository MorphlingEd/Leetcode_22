#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), end = n-1;
        stack<int> zeroInd;
        for (int i = n-1; i >= 0; i--)
            if (nums[i] != 0){
                end = i;
                break;
            }

        int j = end - 1;


        while (j >= 0){
            if (nums[j] != 0){
                j--;
                continue;
            }

            int idx = j;
            j--;

            while (idx < end){
                swap(nums[idx], nums[idx+1]);
                idx++;
            }

            end--;
        }
    }

    void moveZeroesII(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n){
            if (nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

Solution sol;
vector<int> nums;

void testRes(){
    for (int& i : nums)
        cout << i << " ";
    cout << endl;

    sol.moveZeroesII(nums);

    for (int& i : nums)
        cout << i << " ";
    cout << "\n-------------------------------" << endl;
}

int main(){
    nums = {0,1,0,3,12};
    testRes();

    nums = {0};
    testRes();

    nums = {0,0,3,8,0,0};
    testRes();

    return 0;
}