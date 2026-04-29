// Problem : https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int ans=0,t=k;
        for(char c='A';c<='Z';c++){
            int i=0,j=0,k=t;
            while(j<s.size()){
                if(s[j]!=c)k--;j++;
                while(k<0){
                    if(s[i]!=c)k++;
                    i++;
                }
                ans=max(ans, j-i);
            }
        }
        return ans;
    }
}; 

// Good question to understand usecase of two pointer in questions