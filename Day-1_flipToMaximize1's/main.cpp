/* Problem title : Flip to Maximize 1s, link: https://www.geeksforgeeks.org/problems/flip-bits0240/1 */

/*Solution : */

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int one=0,zero=0,ans=0;
        for(auto i:arr){
            if(i==0)zero++;
            else {
                zero--;
                one++;
            }
            ans=max(zero,ans);
            if(zero<0)zero=0;
        }
        return ans+one;
    }
};