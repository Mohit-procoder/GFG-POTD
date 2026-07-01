// problem : https://www.geeksforgeeks.org/problems/count-binary-strings1944/1

// solution:

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  const int MOD = 1000000007;
    long long get(int prev, int s, int k, vector<vector<vector<long long>>> &dp) {
    if (k < 0 || s < 0) return 0;
    if (s == 0) return (k == 0);

    if (dp[prev][s][k] != -1) return dp[prev][s][k];

    int a = 0, b = 0;

    if (prev == 1) {
        if (k > 0) a = get(1, s-1, k-1, dp);
    } else {
        a = get(1, s-1, k, dp);
    }

    b = get(0, s-1, k, dp);

    return dp[prev][s][k] = (a + b) % MOD;
}
    int countStrings(int n, int k) {
        vector<vector<vector<long long>>>dp(2,vector<vector<long long>>(n+1,vector<long long>(k+1,-1)));
        return (get(0,n-1,k,dp)+get(1,n-1,k,dp))%MOD;
    }
};

// time complexity : O(n^2)
// space complexity : O(n*k)