//Problem Link :- https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> tadj[100005];
stack<int> s;
bool used[100005];
bool tused[100005];
 
void dfs(int a){
    used[a]=true;
    for(auto x : adj[a]){
        if(! used[x])
        dfs(x);
    }
    s.push(a);
}
void tdfs(int a){
    tused[a]=true;
    for(auto x : tadj[a]){
        if(! tused[x])
        tdfs(x);
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,i;
    cin >> n >> m;
    
    for(i=1;i<=m;i++){
        cin >> a>> b;
        adj[a].push_back(b);
        tadj[b].push_back(a);
    }
 
    for(i=1;i<=n;i++){
        if(! used[i])
        dfs(i);
    }
   
    int f =0; int eg=s.top();
    while(! s.empty()){
        int node = s.top();
        s.pop();
        if(tused[node])
        continue;
        f++;
        if(f==2){
            cout << "NO\n";
            cout << node << " " << eg;
        }
        tused[node]=true;
        for(auto x : tadj[node]){
            if(! tused[x])
             tdfs(x);
        }
    }
    if(f==1)
    cout << "YES";
    return 0;
}
