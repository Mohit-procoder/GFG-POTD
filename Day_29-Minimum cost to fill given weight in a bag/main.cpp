// problem : https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

// solution:

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        vector<int>dp(w+1,INT_MAX);dp[0]=0;
        for(int i=0;i<cost.size();i++)
            if(cost[i]==-1)continue;
            else for(int j=1;j<=w;j++)
                   if(j>=i+1&&dp[j-i-1]!=INT_MAX)dp[j]=min(dp[j],dp[j-i-1]+cost[i]);
        if(dp[w]==INT_MAX)return -1;return dp[w];
    }
};
