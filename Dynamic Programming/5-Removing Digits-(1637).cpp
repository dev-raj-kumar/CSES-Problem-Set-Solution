// Problem Link :- https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j;
    cin >> n;
    long int dp[n+1]={0};dp[n]=0;
    queue<int> s;
    s.push(n);
    while(! s.empty()){
        n = s.front();
        s.pop();
        for(i=n;i>0;i/=10){
            int d = i%10;
            if(d == 0)
            continue;
            if(dp[n-d] == 0){
            dp[n-d]=(dp[n]+1);
            s.push(n-d);
            }
            
        }
        if(dp[0] > 0)
        break;
    }
    cout << dp[0];
}
