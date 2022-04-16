#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int num = 0;

        for (int j = 0; j < n; j++){
            if (grid[0][j]   == 0)
                dfs(grid, m, n, 0, j);
            if (grid[m-1][j] == 0)
                dfs(grid, m, n, m - 1, j);
        }

        for (int i = 0; i < m; i++){
            if (grid[i][0]   == 0)
                dfs(grid, m, n, i, 0);
            if (grid[i][n-1] == 0)
                dfs(grid, m, n, i, n - 1);
        }

        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j] == 0){
                    num++;
                    dfs(grid, m, n, i, j);
                }

        return num;
    }

    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j){
        grid[i][j] = 1;

        if (i + 1 < m  && grid[i+1][j] == 0)
            dfs(grid, m, n, i + 1, j);
        if (i - 1 >= 0 && grid[i-1][j] == 0)
            dfs(grid, m, n, i - 1, j);
        if (j + 1 < n  && grid[i][j+1] == 0)
            dfs(grid, m, n, i, j + 1);
        if (j - 1 >= 0 && grid[i][j-1] == 0)
            dfs(grid, m, n, i, j - 1);
    }
};

Solution sol;
vector<vector<int>> grid;

void testRes(){
    cout << sol.closedIsland(grid) << endl;
}

int main(){
    grid = {{1,1,1,1,1,1,1,0},
            {1,0,0,0,0,1,1,0},
            {1,0,1,0,1,1,1,0},
            {1,0,0,0,0,1,0,1},
            {1,1,1,1,1,1,1,0}};
    testRes();

    return 0;
}