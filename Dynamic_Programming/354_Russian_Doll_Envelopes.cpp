#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// If true, put env2 (second argument) first
bool compEnvs(const vector<int>& env1, const vector<int>& env2){
    return env1[0] == env2[0] ? env1[1] > env2[1] : env1[0] < env2[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compEnvs);

        vector<int> heights (envelopes.size());
        for (int i = 0; i < heights.size(); i++)
            heights[i] = envelopes[i][1];

        return LIS(heights);
    }

    int LIS(vector<int>& heights){
        int n = heights.size();
        vector<int> top (n, 0);
        int piles = 0;

        for (int i = 0; i < n; i++)
        {
            int poker = heights[i];
            int left = 0, right = piles;

            while (left < right){
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else
                    left = mid + 1;
            }

            if (left == piles)
                piles++;
            top[left] = poker;
        }

        return piles;
    }
};

Solution sol;

void testSol(vector<vector<int>>& envelops){
    cout << sol.maxEnvelopes(envelops) << endl;
}


int main()
{
    vector<vector<int>> envelops = {{5,4},
                                    {6,4},
                                    {6,7},
                                    {2,3}};
    testSol(envelops);

    envelops = {{1,1},{1,1},{1,1}};
    testSol(envelops);

    envelops = {{4,5},
                {4,6},
                {6,7},
                {2,3},
                {1,1}};
    testSol(envelops);

    return 0;
}