// problem : https://www.geeksforgeeks.org/problems/minimum-toogles-to-partition0135/1

// solution :

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int a=0,ans=0;
        for(auto i:arr){
            if(i==1)a++;
            else if(a>0){
                ans++;a--;
            }
        }
        return ans;
    }
};