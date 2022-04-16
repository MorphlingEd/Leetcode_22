#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<short> colors (n, 0);
        vector<vector<int>> graph (n);

        for (int i = 0; i < dislikes.size(); i++){
            int u = dislikes[i][0], v = dislikes[i][1];
            graph[u-1].push_back(v);
            graph[v-1].push_back(u);
        }

        for (int i = 0; i < n; i++)
            if (colors[i] == 0 && !dfs(graph, colors, 1, i+1))
                return false;

        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<short>& colors, short color, int u){
        colors[u-1] = color;

        for (const int& v : graph[u-1])
            if (colors[v-1] == color ||
                (colors[v-1] == 0 && !dfs(graph, colors, -color, v)))
                return false;

        return true;
    }
};

Solution sol;
int n;
vector<vector<int>> dislikes;

void testRes(){
    cout << (sol.possibleBipartition(n, dislikes) ? "True" : "False") << endl;
}

int main(){
    n = 4;
    dislikes = {{1,2},
                {1,3},
                {2,4}};
    testRes();

    n = 3;
    dislikes = {{1,2},
                {1,3},
                {2,3}};
    testRes();

    n = 5;
    dislikes = {{1,2},
                {2,3},
                {3,4},
                {4,5},
                {1,5}};
    testRes();

    return 0;
}