//Problem Link :- https://cses.fi/problemset/task/1691

#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> adj[100001];
//vector<pair<pair<int,int>,int> > edge;
int degree[100001];
vector<int> path;
bool check(){
    for(int i = 1; i<=n;i++){
        if(degree[i] % 2 != 0)
        return false;
    }
    return true;
}
void eulerian(int a){
    auto y = adj[a].begin();
    for(int i = 0;i<adj[a].size();i++){
        if(degree[a] <= 0)
        break;
        
           
            int node = adj[a][i];
             adj[a].erase(y+i);
             
            for(int j = 0;j<adj[node].size();j++){
                if(adj[node][j] == a){
                    adj[node].erase(adj[node].begin() + j);
                    break;
                }
            }
            degree[a]--;
            degree[node]--;
            eulerian(node);
        
    }
    path.push_back(a);
}
int main(){
    //ios_base :: sync_with_stdio(0);
    //cin.tie(NULL);
    int i,a,b;
    cin >> n >> m;
    
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;degree[b]++;
    }
    
    if(check()){
        eulerian(1);
        if(path.size()==m+1){
            for(i=path.size()-1;i>=0;i--)
             printf("%d ",path[i]);
        }
        else
        cout << "IMPOSSIBLE";
        
    }
    else
    cout << "IMPOSSIBLE";
}
