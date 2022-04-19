#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int speed, vector<int>& piles, int h){
        int hour = 0;
        for (int& pile : piles)
            hour += pile / speed + (pile % speed ? 1 : 0);
        return hour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int& pile : piles)
            if (pile > right)
                right = pile;
        right++;

        while (left < right){
            int mid = (left + right) / 2;
            if (canFinish(mid, piles, h))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};

Solution sol;
vector<int> piles;
int h;

void testRes(){
    int res = sol.minEatingSpeed(piles, h);
    cout << res << endl;
}

int main(){
    piles = {3,6,7,11};
    h = 8;
    testRes();

    piles = {30,11,23,4,20};
    h = 5;
    testRes();

    h = 6;
    testRes();

    return 0;
}