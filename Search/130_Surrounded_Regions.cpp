#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = '#';

        for (int i = 0; i < m; i++){
            if (board[i][0] == '#')
                dfs(board, m, n, i, 0);
            if (board[i][n-1] == '#')
                dfs(board, m, n, i, n-1);
        }

        for (int j = 0; j < n; j++){
            if (board[0][j] == '#')
                dfs(board, m, n, 0, j);
            if (board[m-1][j] == '#')
                dfs(board, m, n, m-1, j);
        }

        for (int i = 1; i < m-1; i++)
            for (int j = 1; j < n-1; j++)
                if (board[i][j] == '#')
                    board[i][j] = 'X';
    }


    void dfs(vector<vector<char>>& board, int m, int n, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != '#')
            return;

        board[i][j] = 'O';

        dfs(board, m, n, i+1, j);
        dfs(board, m, n, i-1, j);
        dfs(board, m, n, i, j+1);
        dfs(board, m, n, i, j-1);
    }
};

Solution sol;
vector<vector<char>> board;

void testRes(){
    sol.solve(board);
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main(){
    board = {{'X', 'X', 'X', 'X'},
             {'X', 'O', 'O', 'X'},
             {'X', 'X', 'O', 'X'},
             {'X', 'O', 'X', 'X'}};
    testRes();

    board = {{'O','O'},
             {'O','O'}};
    testRes();

    return 0;
}