#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int right = 0, left = 0, maxLen = 0;
        unordered_map<char, int> window;
        while (right < n){
            // New character to be added in the window
            char c = s[right];
            right++;

            // Update data in the window
            window[c]++;

            // Determine whether to shrink from the left side
            while (window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

Solution sol;
string s;

void testRes(){
    cout << sol.lengthOfLongestSubstring(s) << endl;
}

int main(){
    s = "abcabcbb";
    testRes();

    s = "bbbbbb";
    testRes();

    s = "pwwkew";
    testRes();

    s = "a";
    testRes();

    return 0;
}