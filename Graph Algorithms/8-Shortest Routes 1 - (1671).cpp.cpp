//Problem Link :- https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
 using namespace std;
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,w,i;
    cin >> n >> m;
    vector< pair < int , int > > adj[n+1];
    for(i=1;i<=m;i++){
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    priority_queue< pair < long int ,  int > > pq;
    vector<long int > dis(n+1,1e14);
    dis[1]=0;
    pq.push({0,-1});
    while(! pq.empty()){
        
        int curr = (pq.top().second) * (-1);
        long int curr_d = (pq.top().first) * (-1);
        pq.pop();
        if(curr_d > dis[curr])
        continue;
       
        for(auto x : adj[curr]){
            
            if(curr_d + x.second < dis[x.first]){
                dis[x.first]=curr_d + x.second;
                pq.push({dis[x.first]*(-1),x.first*(-1)});
               
            }
        }
        
    }
    for(i=1;i<=n;i++)
    cout << dis[i] << " ";
    return 0;
}
