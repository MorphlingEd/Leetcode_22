#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canShip(int speed, vector<int>& weights, int days){
        int count = 0, carry = speed;
        for (int& weight : weights){
            if (carry >= weight)
                carry -= weight;
            else{
                count++;
                carry = speed - weight;
            }
        }
        count++;
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int& weight : weights){
            left = max(left, weight);
            right += weight;
        }

        while(left < right){
            int mid = (left + right) / 2;
            if (canShip(mid, weights, days))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};

Solution sol;
vector<int> weights;
int days;

void testRes(){
    cout << sol.shipWithinDays(weights, days) << endl;
}

int main(){
    weights = {1,2,3,4,5,6,7,8,9,10};
    days = 5;
    testRes();

    weights = {3,2,2,4,1,4};
    days = 3;
    testRes();

    weights = {1,2,3,1,1};
    days = 4;
    testRes();

    return 0;
}