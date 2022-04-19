#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int minHeight(int root, vector<vector<int>>& edgeList){
        int depth = 0;
        queue<int> Q;
        unordered_set<int> recorded;

        Q.push(root);
        recorded.insert(root);

        while(!Q.empty()){
            int sz = Q.size();
            for (int i = 0; i < sz;i++){
                int node = Q.front();
                Q.pop();

                for (int neighbor : edgeList[node])
                    if (recorded.find(neighbor) == recorded.end()){
                        recorded.insert(neighbor);
                        Q.push(neighbor);
                    }
            }
            if (!Q.empty()) depth++;
        }

        return depth;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int minDepth = INT_MAX;
        vector<int> res, depths (n);
        vector<vector<int>> edgeList (n);
        for (vector<int>& edge : edges){
            edgeList[edge[0]].push_back(edge[1]);
            edgeList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++){
            depths[i] = minHeight(i, edgeList);
            if (depths[i] < minDepth)
                minDepth = depths[i];
        }

        for (int i = 0; i < n; i++)
            if (depths[i] == minDepth)
                res.push_back(i);

        return res;
    }



    vector<int> findMinHeightTreesII(int n, vector<vector<int>>& edges) {
        queue<int> Q;
        vector<int> res;
        vector<int> degrees (n);
        vector<vector<int>> edgeList (n);
        for (vector<int>& edge : edges){
            edgeList[edge[0]].push_back(edge[1]);
            edgeList[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }

        // The nodes with in-degree will not affect the result
        // Becase given the tree is a connected graph, only when
        // there is a single node in the graph, there can initially appear
        // a node with in-degree 0
        for (int i = 0; i < n; i++)
            if (degrees[i] <= 1)
                Q.push(i);
        // n here counts the remaining nodes (i.e. the nodes that haven't been
        // expanded
        while(n > 2){
            int sz = Q.size();
            n -= sz;
            for (int i = 0; i < sz;i++){
                int node = Q.front();
                Q.pop();

                for (int& adj : edgeList[node]){
                    degrees[adj]--;
                    if (degrees[adj] == 1)
                        Q.push(adj);
                }
            }
        }

        while(!Q.empty()){
            res.push_back(Q.front());
            Q.pop();
        }

        return res;
    }
};

Solution sol;
int n;
vector<vector<int>> edges;

void testRes(){
    vector<int> res = sol.findMinHeightTreesII(n, edges);
    for (int& i : res)
        cout << i << " ";
    cout << "\n--------------------------------" << endl;
}

int main(){
    n = 4;
    edges = {{1,0},
             {1,2},
             {1,3}};
    testRes();

    n = 6;
    edges = {{3,0},
             {3,1},
             {3,2},
             {3,4},
             {5,4}};
    testRes();

    n = 2;
    edges = {{1,0}};
    testRes();

    n = 1;
    edges = {};
    testRes();

    n = 3;
    edges = {{0,1},
             {0,2}};
    testRes();

    return 0;
}

