// problem : https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

// solution :

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int>v(1001, INT_MAX);
        queue<int>q;
        q.push(start);v[start]=0;
        while(!q.empty()){
            int z = q.front();q.pop();
            for(int i=0;i<arr.size();i++){
                if(v[(z*arr[i])%1000]>1+v[z]){
                    v[(z*arr[i])%1000]=1+v[z];q.push((z*arr[i])%1000);
                }
            }
        }
        return v[end]!=INT_MAX?v[end]:-1;
    }
};

// Time complexity : O(n*m), where n is size of array and m is equals to module value , here is 1000.
// space complexity : O(m), as we used queue which can grow upto value of 1000.