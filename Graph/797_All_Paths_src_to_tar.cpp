#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;

        vector<int> temp;
        temp.push_back(0);

        dfs(graph, res, temp);

        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res,
                vector<int>& temp){
        if (temp.back() == graph.size() - 1){
            res.push_back(temp);
            return;
        }

        vector<int> neighbors = graph[temp.back()];
        for (int& neighbor : neighbors){
            temp.push_back(neighbor);

            dfs(graph, res, temp);

            temp.pop_back();
        }
    }
};

Solution sol;
vector<vector<int>> graph;

void testRes(){
    vector<vector<int>> res = sol.allPathsSourceTarget(graph);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

int main(){
    graph = {{1,2},
             {3},
             {3},
             {}};
    testRes();

    graph = {{4,3,1},
             {3,2,4},
             {3},
             {4},
             {}};
    testRes();

    return 0;
}