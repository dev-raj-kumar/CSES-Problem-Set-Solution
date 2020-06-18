#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,u,v;
    cin >> n >> m;
    int par[n+1]={0};
    int dis[n+1]={0};
    bool used[n+1]={false};
    vector<int> adj[n+1];
    for(i=1;i<=m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1]=-1;
    queue<int> q;
    q.push(1);used[1]=true;
    while(! q.empty()){
        int aa = q.front();
        q.pop();
        for(auto x : adj[aa]){
            if(! used[x]){
                used[x]=true;
                dis[x]= dis[aa]+1;
                par[x]=aa;
                q.push(x);
            }
        }
        if(dis[n] > 0)
        break;
    }
    if(dis[n]==0)
    cout << "IMPOSSIBLE\n";
    else{
    cout << dis[n]+1 << "\n";
    vector<int> vec;
    while(par[n] != -1){
        vec.push_back(n);
        n=par[n];
    }
    cout << 1 <<" ";
    for(i=vec.size()-1;i>=0;i--)
    cout << vec[i] << " ";
    }
    
    return 0;
}
