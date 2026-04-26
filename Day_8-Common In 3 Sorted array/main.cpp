// problem : https://www.geeksforgeeks.org/problems/common-elements1132/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int>v;
        int i=0,j=0,k=0;
        while(i<a.size()&&j<b.size()&&k<c.size()){
            if(a[i]==b[j]&&b[j]==c[k]){
                if(v.size()>=1&&v[v.size()-1]!=a[i])v.push_back(a[i]);
                else if(v.size()<1)v.push_back(a[i]);
                i++;j++;k++;
                continue;
            }
            int minn = min(a[i],min(b[j],c[k]));
            if(a[i]==minn)i++;
            if(b[j]==minn)j++;
            if(c[k]==minn)k++;
        }
        return v;
    }
};