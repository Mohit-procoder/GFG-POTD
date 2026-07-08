// problem : https://www.geeksforgeeks.org/problems/geeks-island--170646/1

// solution:

#include <bits/stdc++.h>
using namespace std;

// intution:
/**
 * doing dfs for both station p and q and mrking both towers individually then matching for both p and q.
 */
class Solution
{
public:
    int countCoordinates(vector<vector<int>> &mat)
    {
        vector<vector<bool>> rp(mat.size(), vector<bool>(mat[0].size(), false));
        vector<vector<bool>> rq(mat.size(), vector<bool>(mat[0].size(), false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir(4);
        dir[0] = {0, 1};
        dir[1] = {0, -1};
        dir[2] = {1, 0};
        dir[3] = {-1, 0};
        for (int i = 1; i < mat.size(); i++)
            q.push({i, 0});
        for (int i = 1; i < mat[0].size(); i++)
            q.push({0, i});
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            rp[i][j] = true;
            for (int xx = 0; xx < 4; xx++)
            {
                pair<int, int> z = dir[xx];
                if (i + z.first >= 0 && i + z.first < mat.size() && j + z.second >= 0 && j + z.second < mat[0].size())
                {
                    if (!rp[i + z.first][j + z.second] && mat[i][j] <= mat[i + z.first][j + z.second])
                        q.push({i + z.first, j + z.second});
                }
            }
        }
        for (int i = 0; i < mat.size() - 1; i++)
            q.push({i, mat[0].size() - 1});
        for (int i = 0; i < mat[0].size() - 1; i++)
            q.push({mat.size() - 1, i});
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            rq[i][j] = true;
            for (int xx = 0; xx < 4; xx++)
            {
                pair<int, int> z = dir[xx];
                if (i + z.first >= 0 && i + z.first < mat.size() && j + z.second >= 0 && j + z.second < mat[0].size())
                {
                    if (!rq[i + z.first][j + z.second] && mat[i][j] <= mat[i + z.first][j + z.second])
                        q.push({i + z.first, j + z.second});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (rp[i][j] && rq[i][j])
                    ans++;
            }
        }
        return ans;
    }
};

// time complexity : O(n*m)
// space complexity : O(n*m)