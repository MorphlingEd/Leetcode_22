#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int left = 0, right = 0, minLen = n+1, valid = 0;
        int start = 0;

        unordered_map<char,int> window, pat;
        for (char c : t)
            pat[c]++;

        while (right < n){
            char r = s[right];
            right++;

            if (pat.count(r)){
                window[r]++;
                if (window[r] == pat[r])
                    valid++;
            }


            while (valid == pat.size()){
                if (right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                char l = s[left];
                left++;

                if (pat.count(l)){
                    if (window[l] == pat[l])
                        valid--;
                    window[l]--;
                }
            }

        }

        return minLen > n ? "" : s.substr(start, minLen);
    }
};

Solution sol;
string s;
string t;

void testRes(){
    cout << sol.minWindow(s, t) << endl;
}

int main(){
    s = "ADOBECODEBANC";
    t = "ABC";
    testRes();

    s = "a";
    t = "a";
    testRes();

    s = "a";
    t = "aa";
    testRes();

    s = "abc";
    t = "b";
    testRes();


    return 0;
}