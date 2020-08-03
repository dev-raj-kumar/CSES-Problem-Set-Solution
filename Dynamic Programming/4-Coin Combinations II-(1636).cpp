//Problem Link :- https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    long long int dp[x+1]={0};
    dp[0]=1;
    int i,j;int arr[n];
    for(i=0;i<n;i++)
    cin >> arr[i];
    sort(arr,arr+n);
    for(i=0;i<n;i++){
        for(j=arr[i];j<=x;j++){
            dp[j] += dp[j-arr[i]];
            dp[j] %= (1000000007);
            
        }
    }
    cout << dp[x] << "\n";
}
