#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();

        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int j = 1; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }

        return dp[n][m];
    }
};

Solution s;
void testRes(string word1, string word2){
    cout << s.minDistance(word1 , word2) << endl;
}

int main()
{
    testRes("horse"    , "ros"      );
    testRes("intention", "execution");

    return 0;
}