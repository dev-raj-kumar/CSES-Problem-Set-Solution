//Problem Task :- https://cses.fi/problemset/task/1681

#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[100005];
vector<int> topo;
int n,m;
int in[100005];
 
void toposort(){
    queue<int> q;
    for(int i = 1; i<=n;i++){
        if(in[i]==0)
        q.push(i);
    }
    
    while(! q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto x : adj[node]){
            in[x]--;
            if(in[x]==0)
            q.push(x);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    int a,b,i;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    toposort();
    long int dp[n+1]={0};dp[1]=1;
    for(auto x : topo){
        if(x == n)
        break;
        if(dp[x] > 0)
        for(auto node : adj[x]){
            dp[node] = (dp[node] + dp[x])%1000000007;
        }
    }
    cout << dp[n];
    return 0;
}
