#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

bool isValid(string& str){
    stack<char> S;
    for (char& c : str){
        if (c == '(')
            S.push(c);
        else if (c == ')'){
            if (S.empty()) return false;
            S.pop();
        }
    }
    return S.empty();
}

int isValidII(string& str){
    stack<char> S;
    for (char& c : str){
        if (c == '(')
            S.push(c);
        else if (c == ')'){
            if (S.empty()) return 2;
            S.pop();
        }
    }
    return (S.empty() ? 0 : 1);
}



class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> Q;
        unordered_set<string> records;

        records.insert(s);
        Q.push(s);

        while (!Q.empty()){
            int sz = Q.size();
            bool sign = false;
            for (int i = 0; i < sz; i++){
                string str = Q.front();
                Q.pop();

                if (isValid(str)){
                    res.push_back(str);
                    sign = true;
                    continue;
                } else{
                    if (sign) continue;
                    for (int j = 0; j < str.size(); j++){
                        if (str[j] == '(' || str[j] == ')'){
                            string toPush = str.substr(0, j) + str.substr(j+1);
                            if (records.find(toPush) == records.end()){
                                records.insert(toPush);
                                Q.push(toPush);
                            }
                        }

                    }
                }
            }
            if (sign) break;
        }

        return res;
    }

    vector<string> removeInvalidParenthesesII(string s) {
        vector<string> res;
        queue<string> Q;
        unordered_set<string> records;

        records.insert(s);
        Q.push(s);

        while (!Q.empty()){
            int sz = Q.size();
            bool sign = false;
            for (int i = 0; i < sz; i++){
                string str = Q.front();
                Q.pop();

                int validity = isValidII(str);
                if (validity== 0){
                    res.push_back(str);
                    sign = true;
                    continue;
                } else{
                    if (sign) continue;
                    char toErase = (validity == 1 ? '(' : ')');
                    for (int j = 0; j < str.size(); j++){
                        if (str[j] == toErase){
                            string toPush = str.substr(0, j) + str.substr(j+1);
                            if (records.find(toPush) == records.end()){
                                records.insert(toPush);
                                Q.push(toPush);
                            }
                        }

                    }
                }
            }
            if (sign) break;
        }

        return res;
    }
};

Solution sol;
string s;

void testRes(){
    vector<string> res = sol.removeInvalidParenthesesII(s);
    for (string& str : res)
        cout << str << " ";
    cout << "\n-------------------------" << endl;
}

int main(){

    s = "()())()";
    testRes();

    s = "(a)())()";
    testRes();

    s = ")(";
    testRes();

    s = "()";
    testRes();

    s = ")";
    testRes();

    s = "(";
    testRes();

    s = "()a)(";
    testRes();

    return 0;
}