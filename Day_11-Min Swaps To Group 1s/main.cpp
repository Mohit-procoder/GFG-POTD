// problem : https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int totalOne = accumulate(arr.begin(), arr.end(), 0),i = 0, j = 0, count = 0, ans = INT_MAX;
        if (!totalOne) return -1;
        while (j < totalOne) count += arr[j++]; j--;
        while (j < arr.size()) {
            ans = min(ans, totalOne - count);
            count += (j + 1 < arr.size() ? arr[j + 1] : 0) - arr[i];
            i++; j++;
        }
        return ans;
    }
};