#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp (m+1, vector<int> (n+1, INT_MAX));
        dp[m-1][n-1] = max(-dungeon[m-1][n-1], 0);

        int res;
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--){
                if (i == m-1 && j == n-1) continue;
                res = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(res, 0);
            }

        return dp[0][0] + 1;
    }

    int calculateMinimumHPII(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp (n+1, INT_MAX);
        dp[n-1] = max(-dungeon[m-1][n-1], 0);

        int res;
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--){
                if (i == m-1 && j == n-1) continue;
                res = min(dp[j], dp[j+1]) - dungeon[i][j];
                dp[j] = max(res, 0);
            }

        return dp[0] + 1;
    }
};

Solution sol;
vector<vector<int>> dungeon;

void testRes(){
    cout << sol.calculateMinimumHPII(dungeon) << endl;
}

int main(){
    dungeon = {{-2,-3,3},
               {-5,-10,1},
               {10,30,-5}};
    testRes();

    dungeon = {{0}};
    testRes();

    dungeon = {{0, -10, 20},
               {0 , 0, 100},
               {-1, -1, 0}};
    testRes();

    dungeon = {{0,0,0},
               {1,1,-1}};
    testRes();

    return 0;
}