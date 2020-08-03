Problem Link :- https://cses.fi/problemset/task/1097/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
   ios_base :: sync_with_stdio(0);
   cin.tie(NULL);
   int n,i,j;
   cin >> n;
   long long int dp[n][n];long long int arr[n];long long int s = 0;
   for(i=0;i<n;i++){
       cin >> arr[i];
       s += arr[i];
   }
   for(i=0;i<n;i++)
    dp[i][i]=arr[i];
   
   for(i=1;i<=n-1;i++){
       for(j=0;j<n;j++){
           if(i+j >= n)
           break;
           dp[j][j+i] = max(arr[j]-dp[j+1][j+i],arr[j+i]-dp[j][j+i-1]);
       }
   }
   cout << ((s+dp[0][n-1])/2) << "\n";
}
