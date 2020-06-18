//Problem link :- https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
 
using namespace std;
vector<int> adj[100005];
int color[100005];
int used[100005];
 
bool dfs(int node, int col){
    used[node]=true;
    color[node]=col;
    for(auto x : adj[node]){
        if(!used[x]){
            if(! dfs(x,col^1))
            return false;
        }
        if(color[x] == color[node])
        return false;
    }
    return true;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,u,v;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        color[i]=1;
    }
    for(i=1;i<=m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dev = true;
    for(i=1;i<=n;i++){
        if(!used[i]){
            if(! dfs(i,color[i])){
                dev=false;
                break;
            }
        }
    }
    if(dev){
        for(i=1;i<=n;i++){
            if(color[i]==0)
            color[i]=2;
        cout << color[i] << " ";
        }
    }
    else
    cout << "IMPOSSIBLE";
    return 0;
}
