// problem : https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

// solution:
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int findPosition(int n) {
    if(n == 0 || (n & (n - 1))) return -1;
    
    int pos = 1;
    while(n > 1){
        n >>= 1;
        pos++;
    }
    return pos;
}
};