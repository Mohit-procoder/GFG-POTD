// problem : https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

// solution :

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructList(vector<vector<int>> &q)
    {
        reverse(q.begin(), q.end());
        vector<int> ans;
        ans.push_back(0);
        int t = 0;
        for (int i = 0; i < q.size(); i++)
            if (q[i][0] == 0)
                ans.push_back(q[i][1] ^ t);
            else
                t ^= q[i][1];
        ans[0] ^= t;
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// time complexity : O(q*log(q)) // due to sorting
// space O(1) auxialry space since not using extra space only ans