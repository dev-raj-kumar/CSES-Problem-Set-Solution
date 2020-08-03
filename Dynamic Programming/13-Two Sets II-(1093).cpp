Problem Link :- https://cses.fi/problemset/task/1093/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
   ios_base :: sync_with_stdio(0);
   cin.tie(NULL);
   int n,i,j;
   cin >> n;
   long long int s =(n*(n+1))/2;
   if(s % 2 == 1){
       cout << "0";
   }
   else{
       s /= 2;
       long long int dp[n][s+1];
       dp[0][0]=1;
       for(i=1;i<=s;i++){
           dp[0][i]=0;
       }
       for(i=1;i<n;i++)
       dp[i][0]=1;
       
       for(i=1;i<n;i++){
           for(j=1;j<=s;j++){
               if(j-i >= 0)
               dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%1000000007;
               else
               dp[i][j]=dp[i-1][j];
           }
       }
       cout << dp[n-1][s];
   }
}
