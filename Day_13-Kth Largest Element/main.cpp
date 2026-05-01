// problem : https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

// my solution :

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int>ans(arr.size(),-1);
        priority_queue<int, vector<int>, greater<int>>p;
        for(int i=0;i<k;i++)p.push(arr[i]);
        ans[k-1]=p.top();
        for(int i=k;i<arr.size();i++){
            p.push(arr[i]);
            p.pop(); 
            ans[i]=p.top(); // top pe hamesa kth largest hi rahega coz queue ka size alway k hai.
        }
        return ans;
    }
};
// just used heap property. 