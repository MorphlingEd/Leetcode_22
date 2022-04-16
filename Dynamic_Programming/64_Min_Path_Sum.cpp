#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, INT_MAX));
        dp[1][1] = grid[0][0];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++){
                if (i == 1 && j == 1)
                    continue;

                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }

        return dp[m][n];
    }

    int minPathSumII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp (n);

        for (int i = 0; i < n; i++)
            dp[i] = grid[0][i] + (i ? dp[i-1] : 0);

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (j == 0)
                    dp[j] = grid[i][j] + dp[j];
                else
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);

        return dp[n-1];
    }
};

Solution sol;

void testRes(vector<vector<int>>& grid){
    cout << sol.minPathSumII(grid) << endl;
}

int main(){
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    testRes(grid);

    grid = {{1, 2, 3},
            {4, 5, 6}};
    testRes(grid);

    return 0;
}