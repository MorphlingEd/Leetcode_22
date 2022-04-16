#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_0 = 0, dp_1 = INT_MIN;
        for (int i = 0; i < n; i++){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i]);
        }

        return dp_0;
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

    prices = {1,2,3,4,5};
    testRes();

    prices = {1};
    testRes();

    prices = {1,2};
    testRes();

    return 0;
}