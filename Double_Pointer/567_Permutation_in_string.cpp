#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> window, pat;
        for (char c : s1)
            pat[c]++;
        int n = s2.size(), left = 0, right = 0;
        int valid = 0;

        while (right < n){
            char c = s2[right];
            right++;

            if (pat.count(c)){
                window[c]++;
                if (window[c] == pat[c]) valid++;
            }

            // No need to bother the unsatisfying characters first
            // but to expand the window to the required size
            while(right - left >= s1.size()){
                if (valid == pat.size())
                    return true;

                char l = s2[left];
                left++;
                if (pat.count(l)){
                    if (window[l] == pat[l])
                        valid--;
                    window[l]--;
                }
            }

        }

        return false;
    }
};

Solution sol;
string s1;
string s2;

void testRes(){
    cout << (sol.checkInclusion(s1, s2) ? "True" : "False") << endl;
}

int main(){
    s1 = "ab";
    s2 = "eidbaooo";
    testRes();

    s1 = "bao";
    testRes();

    s1 = "dbo";
    testRes();

    s1 = "ab";
    s2 = "eidboaoo";
    testRes();

    s1 = "a";
    s2 = "a";
    testRes();


    return 0;
}