#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int find(vector<int>& parent, int p){
        while (parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return parent[p];
    }

    void unionSet(vector<int>& parent, vector<int>& sizes, int p, int q){
        int rootP = find(parent, p), rootQ = find(parent, q);
        if (sizes[rootP] > sizes[rootQ]){
            parent[rootQ] = rootP;
            sizes[rootP] += sizes[rootQ];
        } else{
            parent[rootP] = rootQ;
            sizes[rootQ] += sizes[rootP];
        }
    }

    bool isConnected(vector<int>& parent, int p, int q){
        return find(parent, p) == find(parent, q);
    }


    bool equationsPossible(vector<string>& equations) {
        vector<int> parent (26), sizes (26);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        for (string& e : equations)
            if (e[1] == '='){
                unionSet(parent, sizes, e[0] - 'a', e[3] - 'a');
            }

        for (string& e: equations)
            if (e[1] == '!' && isConnected(parent, e[0] - 'a', e[3] - 'a'))
                return false;

        return true;
    }
};

Solution sol;
vector<string> equations;

void testRes(){
    cout << (sol.equationsPossible(equations) ? "True" : "False") << endl;
}

int main(){
    equations = {"b==a", "a==b"};
    testRes();

    equations = {"a==b", "b!=a"};
    testRes();

    equations = {"a==b", "b==c", "a!=c"};
    testRes();

    return 0;
}