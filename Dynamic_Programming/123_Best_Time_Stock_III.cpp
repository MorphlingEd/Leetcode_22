#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int K = 2, n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (K+1, vector<int> (2)));
        for (int i = 0; i <= n; i++){
            dp[i][0][1] = INT_MIN;
            dp[i][0][0] = 0;
        }

        for (int k = 0; k <= K; k++){
            dp[0][k][0] = 0;
            dp[0][k][1] = INT_MIN;
        }

        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= K; k++){
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            }

        return dp[n][K][0];
    }

    int maxProfitII(vector<int>& prices) {
        int K = 2, n = prices.size();
        vector<vector<int>> dp (K+1, vector<int> (2));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;

        for (int k = 0; k <= K; k++){
            dp[k][0] = 0;
            dp[k][1] = INT_MIN;
        }

        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= K; k++){
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i-1]);
                dp[k][1] = max(dp[k][1], dp[k-1][0] - prices[i-1]);
            }

        return dp[K][0];
    }
};

Solution sol;
vector<int> prices;

void testRes(){
    int res = sol.maxProfitII(prices);
    cout << res << endl;
}

int main(){
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