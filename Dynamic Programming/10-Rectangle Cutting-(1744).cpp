//Problem Link :- https://cses.fi/problemset/task/1744/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int a,b,i,j;
    cin >> a >> b;
    long int dp[a+1][b+1];
    dp[1][1]=0;
    for(i=2;i<=b;i++)
    dp[1][i]=i-1;
    for(i=2;i<=a;i++)
    dp[i][1]=i-1;
    
    for(i=2;i<=a;i++){
        for(j=2;j<=b;j++){
            if(i == j)
            dp[i][j]=0;
            else {
                dp[i][j] = min(dp[1][j]+1+dp[i-1][j],dp[i][1]+dp[i][j-1]+1);
                int k;
                for(k=2;k<i;k++){
                dp[i][j] = min(dp[k][j]+dp[i-k][j]+1,dp[i][j]);
                }
                for(k=2;k<j;k++)
                dp[i][j] = min(dp[i][k]+dp[i][j-k]+1,dp[i][j]);
            }
        }
    }
    cout << dp[a][b];
}
