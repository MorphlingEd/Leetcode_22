#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), num = 0;
        vector<vector<bool>> dfs_map (m, vector<bool> (n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1' && !dfs_map[i][j]){
                    num++;
                    dfs(grid, dfs_map, i, j, m, n);
                }

        return num;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& dfs_map,
             int i, int j, int m, int n){
        if (dfs_map[i][j])
            return;

        dfs_map[i][j] = 1;

        if (i-1 >= 0 && grid[i-1][j] == '1')
            dfs(grid, dfs_map, i-1, j, m, n);

        if (i+1 < m && grid[i+1][j] == '1')
            dfs(grid, dfs_map, i+1, j, m, n);

        if (j-1 >= 0 && grid[i][j-1] == '1')
            dfs(grid, dfs_map, i, j-1, m, n);

        if (j+1 < n && grid[i][j+1] == '1')
            dfs(grid, dfs_map, i, j+1, m, n);

    }
};

Solution s;

void testRes(vector<vector<char>>& grid)
{
    cout << s.numIslands(grid) << endl;
}

int main()
{
    vector<vector<int>> grid = {{}}
}