#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool sortVec(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), sortVec);

        for (int j = 1 ; j < n; j++)
            if (intervals[j][1] > intervals[i][1]){
                if (intervals[j][0] <= intervals[i][1])
                    intervals[i][1] = intervals[j][1];
                else{
                    res.push_back(intervals[i]);
                    i = j;
                }
            }

        res.push_back(intervals[i]);

        return res;
    }
};

Solution sol;
vector<vector<int>> intervals;

void testRes(){
    vector<vector<int>> res = sol.merge(intervals);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << endl;
    cout << "-----------------------------" << endl;
}


int main(){
    intervals = {{1,3},
                 {2,6},
                 {8,10},
                 {15,18}};
    testRes();

    intervals = {{1,4},
                 {4,5}};
    testRes();

    intervals = {{1,4},
                 {1,6},
                 {2,7}};
    testRes();

    return 0;
}