#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class UF{
private:
    int counter;
    vector<int> parent;
    vector<int> sizes;

public:
    UF(int n){
        this->counter = counter;
        this->parent = *(new vector<int>(n));
        this->sizes = *(new vector<int>(n,1));

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int p){
        while (parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void unionSets(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);

        if (sizes[rootP] > sizes[rootQ]){
            parent[rootQ] = rootP;
            sizes[rootP] += sizes[rootQ];
        } else {
            parent[rootP] = rootQ;
            sizes[rootQ] += sizes[rootP];
        }
    }

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    int count(){
        return counter;
    }
};