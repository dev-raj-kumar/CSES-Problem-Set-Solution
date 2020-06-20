//Problem Link :- https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;
 
 vector<int>adj[100005];
 int n,m;
 vector<int> vec;
 int in[100005];
 void kahn(){
     queue<int> q;int i;
     for(i=1;i<=n;i++){
         if(in[i]==0)
         q.push(i);
     }
     while(!q.empty()){
         int node = q.front();
         vec.push_back(node);
         q.pop();
         for(auto x : adj[node]){
             in[x]--;
             if(in[x]==0)
             q.push(x);
         }
     }
     if(vec.size()==n){
         for(i=0;i<vec.size();i++)
         cout << vec[i] <<" ";
     }
     else{
         cout << "IMPOSSIBLE\n";
     }
 }
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,a,b;
    cin >> n >> m;
    
    
    for(i=1;i<=m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    kahn();
    
    return 0;
}
