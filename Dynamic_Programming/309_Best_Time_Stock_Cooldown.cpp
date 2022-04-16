#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int> (3));
        dp[0][0] = 0; dp[0][1] = INT_MIN; dp[0][2] = INT_MIN;

        for (int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1],
                           dp[i-1][0] - prices[i-1]);
            dp[i][2] = (i >= 2 ? dp[i-1][1] + prices[i-1] : INT_MIN);
        }

        return max(dp[n][0], dp[n][2]);
    }

    int maxProfitII(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int> (2));
        dp[0][0] = 0; dp[0][1] = INT_MIN;

        for (int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0],
                           dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1],
                           (i >= 2 ? dp[i-2][0] - prices[i-1] : -prices[i-1]));
        }

        return dp[n][0];
    }

    int maxProfitIII(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = INT_MIN, dpPrev1 = dp0, dpPrev2 = dp0;

        for (int i = 1; i <= n; i++){

            if (i >= 3) dpPrev2 = dpPrev1;
            if (i >= 2) dpPrev1 = dp0;

            dp0 = max(dp0, dp1 + prices[i-1]);
            dp1 = max(dp1, (i >= 2 ? dpPrev2 - prices[i-1] : -prices[i-1]));
        }

        return dp0;
    }
};

Solution sol;
vector<int> prices;

void testRes(){
    int res = sol.maxProfitIII(prices);
    cout << res << endl;
}

int main(){
    prices = {1,2,3,0,2};
    testRes();

    prices = {1,2,3,0,0,2};
    testRes();

    prices = {1};
    testRes();

    prices = {3,3,5,0,0,3,1,4};
    testRes();

    prices = {1,2,3,4,5};
    testRes();

    prices = {7,6,4,3,1};
    testRes();

    prices = {1,2,3,4,5};
    testRes();

    prices = {1};
    testRes();

    prices = {1,2};
    testRes();

    return 0;
}