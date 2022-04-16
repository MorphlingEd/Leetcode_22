#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    stack<char> S;


    bool isValid(string s) {
        if (s.size() % 2) return false;

        char left, right;
        for (int i = 0; i < s.size(); i++){
            right = s[i];
            if (right == ')' || right == ']' || right == '}'){
                if (S.empty())
                    return false;

                left = S.top();
                if ((right == ')' && left != '(') ||
                (right == ']' && left != '[') ||
                (right == '}' && left != '{'))
                    return false;

                S.pop();
            }

            else
                S.push(right);
        }

        return S.empty();
    }
};

Solution sol;

void testRes(string s){
    cout << sol.isValid(s) << endl;
}

int main(){
    testRes("()");
    testRes("()[]{}");
    testRes("(]");

    return 0;
}