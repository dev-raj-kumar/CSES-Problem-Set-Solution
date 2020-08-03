Problem Link :- https://cses.fi/problemset/task/1746/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,j;
    cin >> n >> m;
    long int dp[n+1][m+1];
    int arr[n+1];
    for(i=1;i<=n;i++){
            cin >> arr[i];
    }
    for(i=1;i<=m;i++){
        if(arr[1] == 0 || arr[1]==i)
        dp[1][i]=1;
        else
        dp[1][i]=0;
    }
    
    for(i=2;i<=n;i++){
        if(arr[i] == 0 || arr[i] == 1)
        dp[i][1] = (dp[i-1][1] + dp[i-1][2])%1000000007;
        else
        dp[i][1]=0;
        if(arr[i]==0 || arr[i] == m)
        dp[i][m]= (dp[i-1][m-1] + dp[i-1][m])%1000000007;
        else
        dp[i][m]=0;
        for(j=2;j<m;j++){
             if(arr[i] == 0 || arr[i] == j)
             dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%1000000007;
             else
             dp[i][j]=0;
        }
    }
    long int ct = 0;
    for(i=1;i<=m;i++){
    ct += dp[n][i];
    ct %= 1000000007;
    }
    cout << ct;
}
