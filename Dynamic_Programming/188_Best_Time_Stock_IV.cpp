#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector<vector<int>> dp (K + 1, vector<int> (2));
        for (int k = 0; k <= K; k++){
            dp[k][0] = 0;
            dp[k][1] = INT_MIN;
        }

        for (int i = 0; i < n; i++)
            for (int k = 1; k <= K; k++){
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i]);
                dp[k][1] = max(dp[k][1], dp[k-1][0] - prices[i]);
            }

        return dp[K][0];
    }
};

Solution sol;
vector<int> prices;
int k;

void testRes(){
    cout << sol.maxProfit(k, prices) << endl;
}

int main(){
    k = 2;
    prices = {2,4,1};
    testRes();

    k = 2;
    prices = {3,2,6,5,0,3};
    testRes();

    k = 1;
    prices = {7,6,4,3,1};
    testRes();

    return 0;
}