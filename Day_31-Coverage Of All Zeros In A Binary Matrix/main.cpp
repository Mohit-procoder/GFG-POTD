// problem : https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

// solution :

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            int z=0,foz=-1,loz=-1;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0)z++;
                else {
                    if(foz==-1)
                        foz=z;
                    loz=z;
                }
            }
            if(foz!=-1)ans+=(z-foz)+loz;
        }
        for(int i=0;i<mat[0].size();i++){
            int z=0,foz=-1,loz=-1;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]==0)z++;
                else {
                    if(foz==-1)
                        foz=z;
                    loz=z;
                }
            }
            if(foz!=-1)ans+=(z-foz)+loz;
        }
        return ans;
    }
};

// time complexity: O(n*m)
// space complexity : O(1)