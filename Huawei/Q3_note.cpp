#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> nums (n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2 != 0 || n == 1){
        cout << -1;
        return 0;
    }

    int target = sum / 2;
    vector<vector<bool>> dp (n+1, vector<bool> (target + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= target; j++){
            if (j < nums[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        }

    if (!dp[n][target]){
        cout << -1;
        return 0;
    }

    vector<int> res1;
    while (target > 0)
        for (int i = 1; i <= n; i++)
            // The **first** element that makes the target reachable
            if (dp[i][target]){
                res1.push_back(nums[i - 1]);
                target = target - nums[i - 1];

                n = i-1;
                break;
            }



    cout << sum / 2 << endl;

    unordered_map<int,int> freqMap;
    for (int i = 0; i < nums.size(); i++)
        freqMap[nums[i]]++;

    for (int i = 0; i < res1.size(); i++){
        cout << (i == 0 ? "" : " ") << res1[i];
        freqMap[res1[i]]--;
    }
    cout << endl;

    vector<int> res2;
    for (int i = 0; i < nums.size(); i++)
        if (freqMap[nums[i]] > 0){
            res2.push_back(nums[i]);
            freqMap[nums[i]]--;
        }

    for (int i = 0; i < res2.size(); i++){
        if (i == 0)
            cout << res2[i];
        else
            cout << " " << res2[i];
    }

    return 0;

}