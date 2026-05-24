// problem: https://www.geeksforgeeks.org/problems/last-coin-in-a-game-of-alternates/1

// solution :

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coin(vector<int> &arr)
    {
        int i = 0, j = arr.size() - 1;
        while (j > i)
            if (arr[i] > arr[j])
                i++;
            else
                j--;
        return arr[i];
    }
};