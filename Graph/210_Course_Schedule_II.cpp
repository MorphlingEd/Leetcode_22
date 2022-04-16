#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        int src, sz;
        queue<int> Q;
        vector<int> res;
        vector<int> inGraph (n, 0);
        vector<unordered_set<int>> outGraph (n);

        for (const vector<int>& tup : prerequisites){
            inGraph[tup[0]]++;
            outGraph[tup[1]].insert(tup[0]);
        }

        for (int i = 0; i < n; i++)
            if (!inGraph[i])
                Q.push(i);

        while (!Q.empty()){
            sz = Q.size();
            for (int i = 0; i < sz; i++){
                src = Q.front();
                Q.pop();
                res.push_back(src);

                for (const int& tgt : outGraph[src]){
                    inGraph[tgt]--;
                    if (!inGraph[tgt])
                        Q.push(tgt);
                }
            }
        }

        if (res.size() == n)
            return res;
        else
            return {};
    }
};

Solution sol;
int n;
vector<vector<int>> prerequisites;

void testRes(){
    vector<int> res = sol.findOrder(n, prerequisites);
    for (const int& i : res)
        cout << i << " ";
    cout << endl;
}

int main(){
    n = 2;
    prerequisites = {{1,0}};
    testRes();

    n = 4;
    prerequisites = {{1,0},
                     {2,0},
                     {3,1},
                     {3,2}};
    testRes();

    n = 1;
    prerequisites = {};
    testRes();
}