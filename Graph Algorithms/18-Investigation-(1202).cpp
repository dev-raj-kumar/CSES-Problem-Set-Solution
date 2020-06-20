//Problem Link :- https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,i;long long int c;
    cin >> n >> m;
    vector<pair < int , long long int > > adj[n+1];
    long long int dis[n+1];
    long int paths[n+1];
    long int nodeMax[n+1];
    long int nodeMin[n+1];
    
    for(i=0;i<=n;i++){
        dis[i] = 1e18;
        paths[i] = 0;
        nodeMax[i] = 0;
        nodeMin[i] = 1e8;
    }
    
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    priority_queue< pair < long long int , int > > pq;//the default priority queue keeps elemnt in descending 
    // order so we would multiply (-1) to all the distance
    pq.push({0,1});
    dis[1] = 0;
    paths[1] = 1;
    nodeMax[1] = 0;
    nodeMin[1] = 0;
    
    while(! pq.empty()){
        long long int di = pq.top().first *(-1);
        int node = pq.top().second;
        pq.pop();
        
        if(dis[node] < di)
        continue;
        
        for(auto child : adj[node]){
            if(dis[child.first] > dis[node]+ child.second){
                dis[child.first] = child.second+dis[node];
                paths[child.first] = paths[node];
                nodeMax[child.first] = nodeMax[node]+1;
                nodeMin[child.first] = nodeMin[node]+1;
                pq.push({(-1)*dis[child.first] , child.first});
            }
            else if(dis[child.first] == dis[node]+ child.second){
                paths[child.first] = (paths[child.first]+paths[node])%1000000007;
                nodeMax[child.first] = max(nodeMax[child.first],nodeMax[node]+1);
                nodeMin[child.first] = min(nodeMin[child.first],nodeMin[node]+1);
               // pq.push({(-1)*dis[child.first] , child.first}); //not done as there are no negative edges 
               //so no benifits for further child nodes and dijikstra is a kind of BFS approach
            }
        }
    }
    
    
    cout << dis[n] << " " << paths[n] << " " << nodeMin[n] <<" "<< nodeMax[n];
    return 0;
}
