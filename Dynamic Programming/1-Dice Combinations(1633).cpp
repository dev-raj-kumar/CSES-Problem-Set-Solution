Problem link :- https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    int i,j;int arr[]={1,2,3,4,5,6};
    for(i=2;i<=n;i++){
        for(j=0;j<6;j++){
            if(i-arr[j] < 0)
            break;
            else{
            dp[i] += dp[i-arr[j]];
            dp[i] %= (1000000007);
            }
        }
    }
    cout << dp[n];
}
