/** Question:
 * Given an array arr of lengh n , where arr[i] denotes ith worker can work for [i-arr[i] , i+arr[i]] days , arr[i]=-1 means ith worker will not work
 * find minimum number of workers required to complete work of n-1 days , print -1 if it is not possible to complete work for n-1 days
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int>temp(n,0);
    for(int i=0;i<n;i++)
        if(arr[i]!=-1){
            int z = max(0,i-arr[i]);
            arr[z]=max(arr[z] , i+arr[i]);
        }
        int tempp = 1;
    if(arr[0]==0)tempp=0;
    int val = arr[0] ,tmax=arr[0], ans=1,i=1;
    while(val>0&&val<n-1){
        tmax = max(tmax , arr[i]);
        if(i==val+1){
            if(tmax<i){
                tempp=0;
                break;
            }
            ans++;val=tmax;
        }
        i++;
    }
    if(tempp)cout<<ans;
    else cout<<-1;
}