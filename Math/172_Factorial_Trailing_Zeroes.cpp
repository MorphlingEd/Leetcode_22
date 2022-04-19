#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long divisor = 5;
        while(divisor <= n){
            res += n / divisor;
            divisor *= 5;
        }
        return res;
    }
};