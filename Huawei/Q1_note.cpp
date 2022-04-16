#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

// comp used in priority_queue:
// if using std::greater (where return lhs > rhs),
// the smallest will be put first
// but in Java, the least element will be put first according to the ordering

class Server{
public:
    int sid;
    int cpuCnt;
    int memSize;
    Server(int sid, int cpuCnt, int memSize){
        this->sid = sid;
        this->cpuCnt = cpuCnt;
        this->memSize = memSize;
    }
};

bool compare1(const Server& lhs, const Server& rhs){
    if (lhs.cpuCnt == rhs.cpuCnt){
        if (lhs.memSize == rhs.memSize)
            return lhs.sid > rhs.sid;
        else
            return lhs.memSize > rhs.memSize;
    } else{
        return lhs.cpuCnt > rhs.cpuCnt;
    }

}

bool compare2(const Server& lhs, const Server& rhs){
    if (lhs.memSize == rhs.memSize){
        if (lhs.cpuCnt == rhs.cpuCnt)
            return lhs.sid > rhs.sid;
        else
            return lhs.cpuCnt > rhs.cpuCnt;
    } else{
        return lhs.memSize > rhs.memSize;
    }
}

int main(){
    string line, val;
    getline(cin, line);
    int M = stoi(line);
    cout << M << endl;
    //cin >> M;

    // 5 arguments for a CPU:
    // sid, cpu count, memory size
    vector<vector<int>> CPU (M, vector<int> (5));
//    for (int i = 0; i < M; i++)
//        for (int j = 0; j < 5; j++)
//            cin >> CPU[i][j];

    for (int i = 0; i < M; i++){
        getline(cin, line);
        stringstream ss(line);
        for (int j = 0; j < 5; j++){
            getline(ss, val, ',');
            CPU[i][j] = stoi(val);
            cout << CPU[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> target (6);
    for (int i = 0; i < 6; i++)
        cin >> target[i];

    auto compare = [target](Server s1, Server s2){
        if (target[1] == 1)
            return compare1(s1, s2);
        else if (target[1] == 2)
            return compare2(s1, s2);
        return true;
    };
    priority_queue<Server, vector<Server>, decltype(compare)> pq(compare);

    for (int i = 0; i < M; i++)
        if (CPU[i][1] >= target[2] && CPU[i][2] >= target[3] &&
        (target[4] == 9 || CPU[i][3] == target[4]) &&
        (target[5] == 2 || CPU[i][4] == target[5])){
            Server s (CPU[i][0], CPU[i][1], CPU[i][2]);
            pq.push(s);
        }

    int n = min(pq.size(), (size_t) target[0]);
    vector<int> res (n);
    for (int i = 0; i < n; i++){
        res[i] = pq.top().sid;
        pq.pop();
    }
    sort(res.begin(), res.end());

    cout << n;
    for (int i = 0; i < n; i++)
        cout << " " << res[i];

    return 0;
}

