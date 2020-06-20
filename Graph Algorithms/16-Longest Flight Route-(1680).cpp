//Problem Link :- https://cses.fi/problemset/task/1680

#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> adj[100005];
int in[100005];
vector<int> topo;
int dis[100005];
 
void toposort(){
   queue<int> q;
   for(int i = 1 ;i<=n;i++){
       if(in[i] == 0)
       q.push(i);
   }
   while(! q.empty()){
       int node = q.front();
       topo.push_back(node);
       q.pop();
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
   int a,b,i;
   cin >> n >> m;
   for(i=1;i<=m;i++){
       cin >> a >> b;
       adj[a].push_back(b);
       in[b]++;
   }
   for(i=1;i<=n;i++)
   dis[i]= -1;
   dis[1]=0;
   toposort();
   int par[n+1]={0};
   par[1]=0;
   for(auto x : topo){
       if(dis[x] != -1){
           for(auto y : adj[x]){
               if(dis[y] < dis[x] + 1){
                   dis[y]=dis[x] + 1;
                   par[y]=x;
               }
           }
       }
   }
   if(dis[n]== -1)
   cout << "IMPOSSIBLE";
   else{
        cout << (dis[n]+1) <<"\n";
        vector<int> path;
        while(par[n] != 0){
            path.push_back(n);
            n=par[n];
        }
        path.push_back(n);
        for(i=path.size()-1;i>=0;i--)
        cout << path[i] << " ";
   }
   return 0;
}
