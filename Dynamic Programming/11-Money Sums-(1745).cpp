Problem Link :- https://cses.fi/problemset/task/1745/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j;
    cin >> n;
    int ct = 0;
    int arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        ct += arr[i];
    }
    sort(arr,arr+n);
    bool dp[n][ct+1];dp[0][0]=true;
    for(i=1;i<=ct ; i++){
        if(arr[0] == i)
        dp[0][i]=true;
        else
        dp[0][i]=false;
    }
    for(i=1;i<n;i++){
        dp[i][0]=true;
        for(j=1;j<=ct;j++){
            if(j >= arr[i])
            dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i]]);
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> vec;
    for(i=1;i<=ct;i++){
    if(dp[n-1][i])
     vec.push_back(i);
    }
    cout << vec.size() << "\n";
    for(i=0;i<vec.size();i++)
    cout << vec[i] << " ";
    return 0;
}
