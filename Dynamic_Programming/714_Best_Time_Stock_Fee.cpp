#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp0 = 0, dp1 = INT_MIN;

        for (int i = 0; i < n; i++){
            int temp = dp0;
            dp0 = max(dp0, dp1  + prices[i]);
            dp1 = max(dp1, temp - prices[i] - fee);
        }

        return dp0;
    }
};

Solution sol;
vector<int> prices;
int fee;

void testRes(){
    int res = sol.maxProfit(prices, fee);
    cout << res << endl;
}

int main(){
    fee = 2;
    prices = {1,3,2,8,4,9};
    testRes();

    fee = 3;
    prices = {1,3,7,5,10,3};
    testRes();

    return 0;
}

