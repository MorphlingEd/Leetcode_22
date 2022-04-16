#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:

    string upRotate(string state, int i){
        if (state[i] == '9')
            state[i] = '0';
        else
            state[i] += 1;
        return state;
    }

    string downRotate(string state, int i){
        if (state[i] == '0')
            state[i] = '9';
        else
            state[i] -= 1;
        return state;
    }


    int openLock(vector<string>& deadends, string target) {
        int steps = 0;

        unordered_set<string> records;
        queue<string> Q;
        unordered_set<string> deadSet;

        Q.push("0000");
        records.insert("0000");

        for (const string& dead : deadends){
            if (dead == "0000")
                return -1;

            deadSet.insert(dead);
        }


        while(!Q.empty()){
            vector<string> states;

            // Check whether current nodes reach the destination
            while (!Q.empty()){
                string state = Q.front();

                if (state == target)
                    return steps;

                states.push_back(state);
                Q.pop();
            }

            // Expand: only the unvisited and non-dead nodes can be inserted
            for (const string& state : states){
                for (int i = 0; i < 4; i++){

                    string up = upRotate(state, i);
                    if (records.find(up) == records.end()
                            && deadSet.find(up) == deadSet.end()){
                        Q.push(up);
                        records.insert(up);
                    }

                    string down = downRotate(state, i);
                    if (records.find(down) == records.end()
                            && deadSet.find(down) == deadSet.end()){
                        Q.push(down);
                        records.insert(down);
                    }
                }
            }

            steps++;
        }

        return -1;
    }

};

Solution sol;

void testRes(vector<string>& deadends, string target){
    cout << sol.openLock(deadends, target) << endl;
}


int main(){
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    testRes(deadends, target);

    deadends = {"8888"};
    target = "0009";
    testRes(deadends, target);

    deadends = {"0201","0101","0102","1212","2002"};
    target = "0202";
    testRes(deadends, target);

    return 0;
}