#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp (n, 0);
        for (int j = 0; j < n; j++)
            dp[j] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[j] = dp[j] + (j ? dp[j-1] : 0);

        return dp[n-1];
    }
};

Solution sol;

void testRes(int m, int n){
    cout << sol.uniquePaths(m, n) << endl;
}

int main(){
    int m = 3, n = 7;
    testRes(m, n);

    m = 3, n = 2;
    testRes(m, n);

    m = 1, n = 1;
    testRes(m, n);

    return 0;
}