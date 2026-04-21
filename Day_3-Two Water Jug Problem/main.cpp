// problem : https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1


// my solution : 
#include<bits/stdc++.h>
class Solution {
  public:
  // calcultae GCD (or use inbuilt function)
   int gcd(int a , int b){
        if( b==0) return a;
        return gcd( b , a%b);
   }
   
   // actual logic for the solution 
    int fun( int n , int m , int d){
         int i = n ,  j =0;
          int ans =1;
          while(i!= d && j!= d){
              int temp = min(i , m-j);
               j += temp;
               i -= temp;
               ans++;
               if( i ==d || j ==d) break;
                if(i==0){
                    i = n;
                    ans++;
                }
                 if( j==m){
                      j = 0;
                       ans++;
                 }
          }
           return ans;
    }
    // main function to call 
    int minSteps(int m, int n, int d) {
        if( d > max( n , m)) return -1;
        if(d%gcd( n , m) !=0) return -1;
        return min( fun( n , m ,d) , fun( m , n, d));
        
    }
};