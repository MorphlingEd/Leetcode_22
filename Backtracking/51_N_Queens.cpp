#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string (n, '.'));
        vector<vector<string>> res;
        backtrack(res, board, n, 0);

        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& board, int n, int i){
        if (i == n){
            res.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++){
            bool sign = true;
            for (int dr = 1; dr <= i; dr++){
                if (board[i-dr][j] == 'Q' ||
                    (j-dr >= 0 && board[i-dr][j-dr] == 'Q') ||
                    (j+dr < n  && board[i-dr][j+dr] == 'Q')){
                    sign = false;
                    break;
                }
            }
            if (!sign) continue;

            board[i][j] = 'Q';
            backtrack(res, board, n, i+1);
            board[i][j] = '.';
        }
    }
};

Solution sol;
int n;

void testRes(){
    vector<vector<string>> res = sol.solveNQueens(n);

    for (vector<string>& board : res){
        for (auto & i : board)
            cout << i << endl;

        cout << "------------------------------" << endl;
    }
}

int main(){
    for (int i = 1; i <= 5; i++){
        n = i;

        cout << "*******************************" << endl;
        cout << "n = " << n << ":" << endl;
        testRes();
    }

    return 0;
}
