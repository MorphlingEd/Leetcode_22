#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, n, n, "");
        return res;
    }

    void backtrack(vector<string>& res,int left,
                   int right, string curr){
        if (left > right) return;
        if (left < 0 || right < 0) return;
        if (left == 0 && right == 0){
            res.push_back(curr);
            return;
        }

        curr.push_back('(');
        backtrack(res, left - 1, right, curr);
        curr.pop_back();

        curr.push_back(')');
        backtrack(res, left, right - 1, curr);
        curr.pop_back();
    }
};


Solution sol;
int n;

void testRes(){
    vector<string> res = sol.generateParenthesis(n);
    for (string& s : res)
        cout << s << endl;
    cout << "----------------" << endl;
}

int main(){
    n = 3;
    testRes();

    n = 2;
    testRes();

    n = 1;
    testRes();

    return 0;
}