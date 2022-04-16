#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size();
        int fp = 0, sp = 0;
        vector<int> A, B, inter;
        vector<vector<int>> res;

        while (fp < m && sp < n){
            A = firstList[fp];
            B = secondList[sp];

            if (A[1] >= B[0] && B[1] >= A[0]){
                inter = {max(A[0], B[0]), min(A[1], B[1])};
                res.push_back(inter);
            }

            if (A[1] < B[1])
                fp++;
            else
                sp++;
        }

        return res;
    }
};

Solution sol;
vector<vector<int>> firstList;
vector<vector<int>> secondList;

void testRes(){
    vector<vector<int>> res = sol.intervalIntersection(firstList, secondList);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << endl;
    cout << "------------------------\n";
}

int main()
{
    firstList = {{0,2},
                 {5,10},
                 {13,23},
                 {24,25}};
    secondList = {{1,5},
                  {8,12},
                  {15,24},
                  {25,26}};
    testRes();

    firstList = {{1,3},
                 {5,9}};
    secondList = {};
    testRes();

    firstList = {{5,10}};
    secondList = {{5,6}};
    testRes();

    firstList = {{8, 15}};
    secondList = {{2,6}, {8,10},{12,20}};
    testRes();

    return 0;
}