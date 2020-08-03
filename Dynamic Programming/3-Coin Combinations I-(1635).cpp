Problem Link :- https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    long long int dp[x+1]={0};
    dp[0]=1;
    //dp[1]=1;
    int i,j;int arr[n];
    for(i=0;i<n;i++)
    cin >> arr[i];
    sort(arr,arr+n);
    for(i=1;i<=x;i++){
        for(j=0;j<n;j++){
            if(i-arr[j] < 0)
            break;
            else{
            dp[i] += dp[i-arr[j]];
            dp[i] %= (1000000007);
            }
        }
    }
    cout << dp[x] << "\n";
}
