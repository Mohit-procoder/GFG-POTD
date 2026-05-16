// problem : https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1

// my solution:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallest(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 1;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] > ans)
                return ans;
            else
                ans += arr[i];
        return ans;
    }
};