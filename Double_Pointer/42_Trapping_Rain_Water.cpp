#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;

        int n = height.size(), sum = 0;
        vector<int> leftH (n, 0);
        vector<int> rightH (n, 0);

        int highest = height[0];
        for (int i = 1; i < n; i++){
            leftH[i] = highest;
            if (height[i] > highest)
                highest = height[i];
        }

        highest = height[n-1];
        for (int i = n-2; i >= 0; i--){
            rightH[i] = highest;
            if (height[i] > highest)
                highest = height[i];
        }

        for (int i = 0; i < n; i++)
            sum += max(0, min(leftH[i], rightH[i]) - height[i]);

        return sum;
    }

    int trapII(vector<int>& height){
        int n = height.size();
        int left = 0, right = n-1, res = 0;

        // lMax - maximum height in [0:left]
        // rMax - maximum height in [right:n-1]
        int lMax = height[0], rMax = height[n-1];

        while (left <= right){
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            // the lower side can determine its amount of trapping
            if (lMax < rMax){
                res += lMax - height[left];
                left++;
            } else {
                res += rMax - height[right];
                right--;
            }
        }

        return res;
    }
};

Solution sol;
vector<int> height;

void testRes(){
    cout << sol.trapII(height) << endl;
}

int main(){
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    testRes();

    height = {4,2,0,3,2,5};
    testRes();

    height = {4,5};
    testRes();

    height = {2};
    testRes();

    return 0;
}