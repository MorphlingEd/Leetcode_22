#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// if returns true, the first vector should be put first
// The second condition is to make sure that when the start of intervals
// are the same, the one with greater end should be placed first
bool sortCol(const vector<int>& vec1, const vector<int>& vec2){
    return vec1[0] < vec2[0] || (vec1[0] == vec2[0] && vec1[1] > vec2[1]);
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return 1;

        int n = intervals.size(), edge = 0, res = 0;

        sort(intervals.begin(), intervals.end(), sortCol);

        for (int i = 0; i < n; i++)
            if (intervals[i][1] > edge){
                res++;
                edge = intervals[i][1];
            }

        return res;
    }
};

Solution sol;
vector<vector<int>> intervals;

void testRes(){
    cout << sol.removeCoveredIntervals(intervals) << endl;
}

int main(){
    intervals = {{1,4},
                 {3,6},
                 {2,8}};
    testRes();

    intervals = {{1,4},
                 {2,3}};
    testRes();

    intervals = {{1,9},
                 {1,10},
                 {2,3},
                 {3,7},
                 {4,6}};
    testRes();

    intervals = {{1,2},
                 {2,3},
                 {3,4},
                 {4,5}};
    testRes();

    intervals = {{1,4},
                 {1,5},
                 {1,6}};
    testRes();

    return 0;
}