// problem : https://www.geeksforgeeks.org/problems/asteroid-collision/1
#include<bits/stdc++.h>
using namespace std;

// my solution:
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int>s;
        for(auto i:arr){
            while(!s.empty()&&((s.top()<0&&i>0)||(s.top()>0&&i<0))&&(abs(s.top())<abs(i)))s.pop();
            if(s.empty())s.push(i);
            else if(((s.top()<0&&i>0)||(s.top()>0&&i<0))&&(abs(s.top())==abs(i)))s.pop();
            else if(((s.top()<0&&i<0)||(s.top()>0&&i>0)))s.push(i);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// this was a good question to understand usecase of stack