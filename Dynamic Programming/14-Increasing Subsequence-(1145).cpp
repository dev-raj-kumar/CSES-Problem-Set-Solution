Problem Link :- https://cses.fi/problemset/task/1145/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i;
    cin >> n;
    int arr[n],dp[n];
    for(i=0;i<n;i++)
    cin >> arr[i];
    dp[0]=arr[0];int id = 1;
    for(i=1;i<n;i++){
        int it = lower_bound(dp,dp+id,arr[i])-dp;
        if(it >= id){
            dp[id]=arr[i];
            id++;
        }
        else
        dp[it]=arr[i];
    }
    cout << id;
    return 0;
}
