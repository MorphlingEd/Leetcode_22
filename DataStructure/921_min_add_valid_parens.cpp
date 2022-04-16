#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:


    int minAddToMakeValid(string s) {
        stack<char> S;
        char right;
        int num = 0;
        for (int i = 0; i < s.size(); i++){
            right = s[i];
            if (s[i] == ')'){
                if (S.empty())
                    num++;
                else
                    S.pop();
            }
            else
                S.push(right);
        }

        return num + S.size();
    }
};

Solution sol;

void testRes(string s){
    cout << sol.minAddToMakeValid(s) << endl;
}

int main(){
    testRes("())");
    testRes("(((");
    testRes("()()()))");

    return 0;
}