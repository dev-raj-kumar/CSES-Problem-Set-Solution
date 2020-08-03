Problem Link :- https://cses.fi/problemset/task/1639/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    string x = ""; string y = "";
    cin >> x; cin >> y;
    int n,m,i,j;
    n =  x.length();  m = y.length();
    int dp[n][m];
    if(x[0] != y[0])
    dp[0][0]=1;
    else
    dp[0][0]=0;
    for(i=1;i<m;i++){
        if(x[0] == y[i])
        dp[0][i]= i;
        else
        dp[0][i] = dp[0][i-1]+1;
    }
    for(i=1;i<n;i++){
        if(x[i] == y[0])
        dp[i][0] = i;
        else
        dp[i][0]= dp[i-1][0]+1;
    }
    
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(x[i] == y[j])
            dp[i][j] = dp[i-1][j-1];
            else
            dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout << dp[n-1][m-1];
}
