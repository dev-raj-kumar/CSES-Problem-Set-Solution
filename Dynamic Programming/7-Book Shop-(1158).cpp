Problem Link :- https://cses.fi/problemset/task/1158/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j,x;
    cin >> n >> x;
    int pr[n+1];pr[0]=0;
    int pg[n+1];pg[0]=0;
    for(i=1;i<=n;i++)
    cin >> pr[i];
    for(i=1;i<=n;i++)
    cin >> pg[i];
    int dp[n+1][x+1];
    for(i=0;i<=n;i++)
    dp[i][0]=0;
    for(i=0;i<=x;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=x;j++){
            if(j-pr[i] >= 0)
            dp[i][j] = max(dp[i-1][j-pr[i]]+pg[i],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    cout << dp[n][x];
}
