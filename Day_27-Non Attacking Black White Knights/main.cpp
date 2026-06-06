// problem : https://www.geeksforgeeks.org/problems/black-and-white-1587115620/1

// solution:

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numOfWays(int n, int m) {
        vector<pair<int,int>>dir(8);long long ans=0;
        dir[0]={2,1};dir[1]={2,-1};dir[2]={-2,1};dir[3]={-2,-1};dir[4]={1,2};dir[5]={-1,2};dir[6]={1,-2};dir[7]={-1,-2};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long t=0;
                for(int k=0;k<8;k++){
                int x=i,y=j;
                x+=dir[k].first;y+=dir[k].second;
                if(x>=0&&y>=0&&x<n&&y<m)t++;
                }
                ans+=((n*m-1)-t);
            }
        }
        return ans;
    }
};