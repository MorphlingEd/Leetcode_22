#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> adjLists = {{1, 3},
                                    {0, 2, 4},
                                    {1, 5},
                                    {0, 4},
                                    {1, 3, 5},
                                    {2, 4}};

    string swap(string state, int i, int j){
        char temp = state[i];
        state[i] = state[j];
        state[j] = temp;
        return state;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int steps = 0;
        queue<string> Q;
        unordered_set<string> record;
        string target = "123450";

        // convert the 2-d vector into string for hashing
        string root;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                root.push_back(board[i][j] + '0');

        Q.push(root);

        while (!Q.empty()){
            int sz = Q.size();

            for (int i = 0; i < sz; i++){
                string state = Q.front();
                Q.pop();

                if (state == target)
                    return steps;

                // find index of zero
                int idx = 0;
                for (int j = 0; j < 6; j++)
                    if (state[j] == '0')
                        idx = j;

                for (int adj : adjLists[idx]){
                    string newState = swap(state, idx, adj);
                    if (record.find(newState) != record.end())
                        continue;
                    Q.push(newState);
                    record.insert(newState);
                }
            }

            steps++;
        }

        return -1;
    }
};

Solution sol;
vector<vector<int>> board;

void testRes(){
    cout << sol.slidingPuzzle(board) << endl;
}

int main()
{
    board = {{1,2,3},
             {4,0,5}};
    testRes();

    board = {{1,2,3},
             {5,4,0}};
    testRes();

    board = {{4,1,2},
             {5,0,3}};
    testRes();
}