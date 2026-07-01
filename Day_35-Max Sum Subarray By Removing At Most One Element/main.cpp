// question : https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1

// solution :
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
         int curr_sum = arr[0]; 
        int max_sum = arr[0];
        int skipped_sum = 0;
        for( int i=1; i<arr.size(); i++){
            skipped_sum = max(curr_sum, skipped_sum + arr[i]);
            curr_sum = max(curr_sum + arr[i], arr[i]);
            max_sum = max(max_sum, max(curr_sum, skipped_sum));
        }
        return max_sum;
    }
};