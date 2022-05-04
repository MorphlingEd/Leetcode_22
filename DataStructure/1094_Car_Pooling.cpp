#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    // TLE version
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto cmp = [](const vector<int>& trip1, const vector<int>& trip2){
            return trip1[1] > trip2[1] || (trip1[1] == trip2[1] && trip1[2] > trip2[2]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (vector<int>& trip : trips){
            if (trip[0] > capacity) return false;
            pq.push(trip);
        }

        while(!pq.empty()){
            vector<int> trip1 = pq.top();
            pq.pop();

            if (!pq.empty() && pq.top()[1] < trip1[2]){
                vector<int> trip2 = pq.top();
                pq.pop();

                if (trip1[0] + trip2[0] > capacity)
                    return false;

                vector<int> seg1 = {trip1[0]+trip2[0],
                                    trip2[1], min(trip1[2], trip2[2])};
                pq.push(seg1);

                if (trip1[2] > trip2[2]){
                    vector<int> seg2 = {trip1[0],
                                        trip2[2], trip1[2]};
                    pq.push(seg2);
                } else if (trip1[2] < trip2[2]){
                    vector<int> seg2 = {trip2[0],
                                        trip1[2],trip2[2]};
                    pq.push(seg2);
                }
            }
        }

        return true;
    }

    // Difference Array
    bool carPoolingII(vector<vector<int>>& trips, int capacity) {
        int l = 1001, r = -1, len;
        for (vector<int>& trip : trips){
            if (trip[2] > r)
                r = trip[2];
            if (trip[1] < l)
                l = trip[1];
        }

        len = r - l + 1;
        vector<int> diff (len);
        for (vector<int>& trip : trips){
            diff[trip[1]-l] += trip[0];
            diff[trip[2]-l] -= trip[0]; // Because right-exclusive, no need to increment right range value
        }

        if (diff[0] > capacity) return false;
        for (int i = 1; i < len; i++){
            diff[i] += diff[i-1];
            if (diff[i] > capacity) return false;
        }

        return true;
    }
};

Solution sol;
vector<vector<int>> trips;
int capacity;

void testRes(){
    cout << (sol.carPooling(trips, capacity) ? "True" : "False") << endl;
}

int main(){
    // False
    trips = {{2,1,5},
             {3,3,7}};
    capacity = 4;
    testRes();

    // True
    capacity = 5;
    testRes();


    // False
    trips  = {{2,1,5},
              {3,3,7},
              {3,3,5}};
    capacity = 4;
    testRes();

    // True
    capacity = 8;
    testRes();

    // True
    trips = {{2,1,5}};
    capacity = 2;
    testRes();

    // False
    capacity = 1;
    testRes();


    // True
    trips = {{2,2,3},
             {2,3,4}};
    capacity = 2;
    testRes();

    // False
    trips = {{1,2,3},
             {5,1,6}};
    capacity = 5;
    testRes();

    // True
    capacity = 6;
    testRes();

    return 0;
}
