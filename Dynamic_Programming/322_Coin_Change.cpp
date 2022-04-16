#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, -1);
        dp[0] = 0;

        for (int m = 1; m <= amount; m++){
            int min = INT_MAX;
            for (int coin : coins)
                if (coin <= m && dp[m - coin] >= 0 && dp[m - coin] < min)
                    min = dp[m - coin];
            if (min < INT_MAX)
                dp[m] = min + 1;
        }

        return dp[amount];
    }
};

Solution sol;

void testSol(vector<int>& coins, int amount){
    cout << sol.coinChange(coins, amount) << endl;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    testSol(coins, amount);

    coins = {2};
    amount = 3;
    testSol(coins, amount);

    coins = {1};
    amount = 0;
    testSol(coins, amount);

    return 0;
}