//Problem Link :- https://cses.fi/problemset/task/1638/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j;
    cin >> n;
    long int dp[n][n];
    dp[0][0]=1;
    char arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cin >> arr[i][j];
    }
    if(arr[0][0] == '*' || arr[n-1][n-1] == '*')
    cout << 0;
    else{
    for(i=1;i<n;i++){
        if(arr[0][i] == '.')
        dp[0][i]=dp[0][i-1];
        else
        dp[0][i]=0;
        if(arr[i][0] == '.')
        dp[i][0]=dp[i-1][0];
        else
        dp[i][0]=0;
    }
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(arr[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%(1000000007);
            }
            else
            dp[i][j]=0;
        }
    }
    cout << dp[n-1][n-1] << "\n";
    }

}
