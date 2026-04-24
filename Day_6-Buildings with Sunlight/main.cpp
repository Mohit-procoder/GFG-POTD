// Problem : https://www.geeksforgeeks.org/problems/buildings-receiving-sunlight3032/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int dadaji = 1, fufaji = arr[0];
        for(int i=1;i<arr.size();i++)if(arr[i]>=fufaji){
            dadaji++;fufaji=arr[i];
        }
        return dadaji;
    }
};