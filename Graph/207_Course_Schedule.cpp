#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int num = 0, sz, src;
        vector<int> inCounter (n, 0);
        vector<unordered_set<int>> outGraph (n);
        queue<int> Q;

        for (const vector<int>& tup : prerequisites){
            inCounter[tup[1]]++;
            outGraph[tup[0]].insert(tup[1]);
        }

        for (int i = 0; i < n; i++)
            if (!inCounter[i])
                Q.push(i);

        while (!Q.empty()){
            sz = Q.size();
            for (int i = 0; i < sz; i++){
                src = Q.front();
                Q.pop();

                for (const int& tgt : outGraph[src]){
                    inCounter[tgt]--;
                    if (!inCounter[tgt])
                        Q.push(tgt);
                }

                num++;
            }

        }

        return num == n;
    }
};

Solution sol;
int n;
vector<vector<int>> prerequisites;

void testRes(){
    cout << (sol.canFinish(n, prerequisites) ? "True" : "False") << endl;
}

int main(){
    n = 2;
    prerequisites = {{1,0}};
    testRes();

    n = 2;
    prerequisites = {{1,0},
                     {0,1}};
    testRes();

    n = 5;
    prerequisites = {{0,1},
                     {1,2},
                     {2,3},
                     {2,4},
                     {3,4},
                     {4,1}};
    testRes();

    return 0;
}