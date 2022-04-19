#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<functional>
using namespace std;

void nextMove(int n, int r, int c, vector <string> grid){
    int pr = -1, pc = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 'p'){
                pr = i;
                pc = j;
            }

    if (pr == r)
        cout << (c > pc ? "LEFT" : "RIGHT") << endl;
    else
        cout << (r > pr ? "UP" : "DOWN") << endl;
}

int main(void) {
    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}