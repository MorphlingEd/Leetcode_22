#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;

    int maxSLA = 0, time = 0, res = 0;
    vector<vector<int>> orders (n, vector<int> (2));
    for (int i = 0; i < n; i++){
        cin >> orders[i][0] >> orders[i][1];
        if (orders[i][0] > maxSLA)
            maxSLA = orders[i][0];
    }

    auto cmp = [](const vector<int>& o1, const vector<int>& o2){
        if (o1[0] == o2[0])
            return o1[1] < o2[1];
        else
            return o1[0] > o2[0];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (const vector<int>& order : orders)
        pq.push(order);

    while (time < maxSLA && !pq.empty()){
        vector<int> order = pq.top();
        pq.pop();

        res += order[1];

        time++;
        while (!pq.empty() && pq.top()[0] <= time) pq.pop();
    }

    cout << res;

    return 0;
}