//Problem Link :- https://cses.fi/problemset/task/1693

#include<bits/stdc++.h>
using namespace std;
 
vector<int> adj[100005];
int ind[100005];
int outd[100005];
int n,m;
vector<int> path;
 
bool check(){
    if(outd[1]-ind[1] != 1)
    return false;
    if(ind[n]-outd[n] != 1)
    return false;
    
    for(int i=2;i<n;i++){
        if(ind[i] != outd[i])
        return false;
    }
    return true;
}
void eulerian(int a){
    while(outd[a] > 0){
        int next_edge = adj[a][--outd[a]];
        eulerian(next_edge);
    }
    path.push_back(a);
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int i,a,b;
    cin >> n >> m;
    
    for(i=1;i<=m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
        outd[a]++;
    }
    
    if(check()){
        eulerian(1);
        if(path.size()== m+1){
            for(i=path.size()-1;i>=0;i--)
            cout << path[i] << " ";
        }
        else
        cout << "IMPOSSIBLE";
    }
    else
    cout << "IMPOSSIBLE";
}
