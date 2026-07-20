// problem : https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1

// solution:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findPrefixes(vector<string>& arr) {
        unordered_map<string, int> mp;
        vector<string> ans;

        for (string &s : arr) {
            string prefix = "";
            for (char ch : s) {
                prefix += ch;
                mp[prefix]++;
            }
        }
        for (string &s : arr) {
            string prefix = "";
            int flag=0;
            for (char ch : s) {
                prefix += ch;
                if (mp[prefix] == 1) {
                    ans.push_back(prefix);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(s);
            }
        }

        return ans;
    }
};