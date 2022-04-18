#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window, pat;
        for (char c : p) pat[c]++;

        vector<int> res;
        int n = s.size(), left = 0, right = 0, validity = 0;

        while (right < n){
            char c = s[right];
            right++;

            if (pat.count(c)){
                window[c]++;
                if (window[c] == pat[c])
                    validity++;
            }

            while (right - left >= p.size()){
                if (validity == pat.size())
                    res.push_back(left);

                char l = s[left];
                left++;
                if (pat.count(l)){
                    if (window[l] == pat[l])
                        validity--;
                    window[l]--;
                }
            }
        }

        return res;
    }
};

Solution sol;
string s;
string p;

void testRes(){
    vector<int> res = sol.findAnagrams(s, p);
    for (int& i : res)
        cout << i << " ";
    cout << endl;
}

int main(){
    s = "cbaebabacd";
    p = "abc";
    testRes();

    s = "abab";
    p = "ab";
    testRes();

    s = "ababa";
    p = "ab";
    testRes();

    return 0;

}