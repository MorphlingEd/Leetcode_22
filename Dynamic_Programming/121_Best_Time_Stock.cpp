#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = INT_MIN;

        for (int i = 1; i <= n; i++){
            dp1 = max(dp1, -prices[i-1]);
            dp0 = max(dp0, dp1 + prices[i-1]);
        }

        return dp0;
    }
};

Solution sol;
vector<int> prices;

void testRes(){
    int res = sol.maxProfit(prices);
    cout << res << endl;
}

int main(){
    prices = {7,1,5,3,6,4};
    testRes();

    prices = {7,6,4,3,1};
    testRes();

    prices = {1};
    testRes();

    prices = {1,2};
    testRes();

    return 0;
}