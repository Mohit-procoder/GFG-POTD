// Problem : https://www.geeksforgeeks.org/problems/mean-of-range-in-array2123/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> s(n, arr[0]), ans(q);
        for (int i = 1; i < n; i++)
            s[i] = s[i - 1] + arr[i];
        for (int i = 0; i < q; i++)
            ans[i] =
                (s[queries[i][1]] - s[queries[i][0]] + arr[queries[i][0]]) /
                (queries[i][1] - queries[i][0] + 1);
        return ans;
    }
};