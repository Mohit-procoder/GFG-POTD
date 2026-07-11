// problem : https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1

// solurion:
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getans(vector<vector<int>> &mat, vector<vector<int>> &v, int i, int j, int x, int y, int p, int &ans)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return;
        if (mat[i][j] == 0 || v[i][j])
            return;
        if (i == x && j == y)
            ans = max(ans, p);
        else
        {
            v[i][j] = 1;
            getans(mat, v, i + 1, j, x, y, p + 1, ans);
            getans(mat, v, i - 1, j, x, y, p + 1, ans);
            getans(mat, v, i, j + 1, x, y, p + 1, ans);
            getans(mat, v, i, j - 1, x, y, p + 1, ans);
            v[i][j] = 0;
        }
    }
    int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
    {
        vector<vector<int>> v(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        int ans = -1;
        getans(mat, v, xs, ys, xd, yd, 0, ans);
        return ans;
    }
};

// backtracking easy implementation
