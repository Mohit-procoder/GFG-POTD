// problem:  https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

// my solution:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        stack<int> s;
        for (auto i : arr)
            if (s.size() && (s.top() ^ i) < 0)
                s.pop();
            else
                s.push(i);
        vector<int> ans;
        while (s.size())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};