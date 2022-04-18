#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return recur(expression, 0, expression.size()-1);
    }

    vector<int> recur(string& expression, int lo, int hi){
        vector<int> res;
        for (int i = lo + 1; i < hi; i++){
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*'){
                vector<int> lRes = recur(expression, lo, i-1);
                vector<int> rRes = recur(expression, i+1, hi);
                for (const int& l : lRes)
                    for (const int& r : rRes){
                        if (c == '+')
                            res.push_back(l + r);
                        else if (c == '*')
                            res.push_back(l * r);
                        else if (c == '-')
                            res.push_back(l - r);
                    }
            }
        }

        if (res.empty())
            return {stoi(expression.substr(lo, hi+1))};

        return res;
    }

};

Solution sol;
string expression;

void testRes(){
    vector<int> res = sol.diffWaysToCompute(expression);
    for (int& num : res)
        cout << num << " ";
    cout << endl;
}

int main(){
    expression = "12-1-1";
    testRes();

    expression = "11";
    testRes();

    expression = "2*3-4*5";
    testRes();

    expression = "4*9-5*6+7";
    testRes();

    return 0;
}