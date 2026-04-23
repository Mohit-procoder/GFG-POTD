// Problem : https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

// my solution :

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int s = accumulate(arr.begin(),arr.end(),0) , t=0;
        for(int i=0;i<arr.size();i++){
            t+=arr[i];
            if(t==s-t)return true;
            if(t>s-t)return false;
        }
        return false;
    }
};
