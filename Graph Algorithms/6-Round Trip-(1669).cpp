//Problem Link :- https://cses.fi/problemset/task/1669

#include <bits/stdc++.h> 
using namespace std;
vector<int> adj[100005];
vector<int> vec;
int pre;
int used[100005];
 
bool dfs(int node, int par){
    used[node]=true;
   vec.push_back(node);
    for(auto x : adj[node]){
       if(! used[x]){
           if(dfs(x,node)){
           return true;
           }
       }
       else if(x != par){
           vec.push_back(x);
           pre = x;
           return true;
       }
    }
    vec.erase(vec.end()-1);
    return false;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,u,v;
    cin >> n >> m;
    
    for(i=1;i<=m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dev = false;
    for(i=1;i<=n;i++){
        if(!used[i]){
            if( dfs(i,-1)){
                dev=true;
                break;
            }
            vec.clear();
        }
    }
    if(dev){int j;
        for(i=0;i<vec.size();i++)
        if(vec[i]==pre){
            j=i;
            break;
        }
        cout << vec.size()-i << "\n";
        for(i=j;i<vec.size();i++){
        cout << vec[i] << " ";
        }
    }
    else
    cout << "IMPOSSIBLE";
    return 0;
}
