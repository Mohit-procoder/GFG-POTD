// problem : https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

// my solution:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(vector<int> &arr)
    {
        for (int i = 0; i <= arr.size() / 2 - 1; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < arr.size() && arr[i] < arr[left])
                return false;
            if (right < arr.size() && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};
