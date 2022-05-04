#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    // Difference Array
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff (n, 0), res (n);
        for (vector<int>& booking : bookings){
            int l = booking[0], r = booking[1], val = booking[2];
            diff[l-1] += val;
            if (r != n) diff[r] -= val; // (r - 1 + 1)
        }

        res[0] = diff[0];
        for (int i = 1; i < n; i++)
            res[i] = res[i-1] + diff[i];

        return res;
    }

    vector<int> corpFlightBookingsII(vector<vector<int>>& bookings, int n) {
        vector<int> diff (n, 0);
        for (vector<int>& booking : bookings){
            diff[booking[0]-1] += booking[2];
            if (booking[1] != n) diff[booking[1]] -= booking[2]; // (r - 1 + 1)
        }

        for (int i = 1; i < n; i++)
            diff[i] = diff[i-1] + diff[i];

        return diff;
    }
};

Solution sol;
vector<vector<int>> bookings;
int n;

void testRes(){
    vector<int> res = sol.corpFlightBookingsII(bookings, n);
    for (int& i : res)
        cout << i << " ";
    cout << endl;
}

int main(){
    bookings = {{1,2,10},
                {2,2,15}};
    n = 2;
    testRes();

    bookings = {{1,2,10},
                {2,3,20},
                {2,5,25}};
    n = 5;
    testRes();

    return 0;
}
