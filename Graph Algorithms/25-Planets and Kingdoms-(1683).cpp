//Problem Link :- https://cses.fi/problemset/task/1683

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> tadj[100005];
stack<int> s;
bool used[100005];
bool tused[100005];
vector<int> vec;
int king[100005];
 
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
    vec.push_back(a);
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
   
    int f =0;
    while(! s.empty()){
        int node = s.top();
        s.pop();
        if(tused[node])
        continue;
        f++;
       
        tused[node]=true;
        vec.push_back(node);
        for(auto x : tadj[node]){
            if(! tused[x])
             tdfs(x);
        }
        for(int j = 0;j< vec.size();j++){
            king[vec[j]]=f;
        }
        vec.clear();
    }
    cout << f << "\n";
    for(i=1;i<=n;i++)
    cout << king[i] << " ";
    return 0;
}
