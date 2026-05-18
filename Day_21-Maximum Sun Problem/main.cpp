// problem : https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

// my solution :

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(int n) {
        if(n<=4)return n;
        return max(n, maxSum(n/2)+maxSum(n/3)+maxSum(n/4));
    }
};