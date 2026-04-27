// problem : https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

// my solution :
class Solution {
  public:
    int smallestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0,j=0,ans=INT_MAX;
        while(j<s.size()){
            m[s[j++]]++;
            while(m.size()>=3){
                ans=min(ans,j-i);
                --m[s[i]]==0?m.erase(s[i]):1;i++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
