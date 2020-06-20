Problem Link :- https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,q,i;
    cin >> n >> q;
    int dp[32][n+1];
    for(i=1;i<=n;i++){
       cin >> dp[0][i];
    }
    for(i=1;i<=31;i++){
        int j;
        for(j=1;j<=n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
   
    int x,k;
    while(q > 0){
        cin >> x >> k;
        if(k==1)
        cout << dp[0][x] << "\n";
        else if(dp[0][x] == x)
        cout << x << "\n";
        else{
            int ans=x;
            while(k > 0){
                int ind = log2(k);
                ans = dp[ind][ans];
                k -= (1 << ind);
            }
            cout << ans << "\n";
        }
        q--;
    }
    return 0;
}
