#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, n = nums.size();
        while(right < n){
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};

Solution sol;
vector<int> nums;
int val;

void testRes(){
    int k = sol.removeElement(nums, val);
    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << "\n--------------------------" << endl;
}

int main(){
    nums = {3,2,2,3};
    val = 3;
    testRes();

    nums = {0,1,2,2,3,0,4,2};
    val = 2;
    testRes();

    return 0;
}