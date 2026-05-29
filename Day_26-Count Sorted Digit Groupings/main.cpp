// problem : https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

// solution:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int prev, string &s, int i, vector<vector<int>> &dp)
    {
        if (i == s.size())
            return 1;
        if (dp[prev][i] != -1)
            return dp[prev][i];
        int ans = 0, dig = 0, z = i;
        while (i < s.size())
        {
            dig += s[i] - 48;
            i++;
            if (dig >= prev)
            {
                if (dp[dig][i] != -1)
                    ans += dp[dig][i];
                else
                {
                    dp[dig][i] = solve(dig, s, i, dp);
                    ans += dp[dig][i];
                }
            }
        }
        return dp[prev][z] = ans;
    }
    int validGroups(string &s)
    {
        int dig = 0;
        for (auto i : s)
            dig += i - 48;
        vector<vector<int>> dp(dig + 1, vector<int>(s.size() + 1, -1));
        return solve(0, s, 0, dp);
    }
};

// it was eady dp question , 