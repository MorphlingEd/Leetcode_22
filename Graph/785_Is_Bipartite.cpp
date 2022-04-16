#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<short> colors (n, 0);

        for (int i = 0 ; i < n; i++)
            if (colors[i] == 0 && !dfs(graph, colors, 1, i))
                    return false;

        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<short>& colors, short color, int u){
        colors[u] = color;

        // Expand: if the neighbor has the same color or the further expansion
        // finds same-color neighbors, return false
        for (const int& v : graph[u])
            if (colors[v] == color ||
                (colors[v] == 0 && !dfs(graph, colors, -color, v)))
                return false;

        return true;
    }
};

Solution sol;
vector<vector<int>> graph;

void testRes(){
    cout << (sol.isBipartite(graph) ? "True" : "False") << endl;
}

int main(){
    graph = {{1,2,3},
             {0,2},
             {0,1,3},
             {0,2}};
    testRes();

    graph = {{1,3},
             {0,2},
             {1,3},
             {0,2}};
    testRes();

    graph = {{1,2},
             {0},
             {0}};
    testRes();

    return 0;
}