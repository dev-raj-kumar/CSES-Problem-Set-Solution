//Problem Link :- https://cses.fi/problemset/task/1196

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,j,a,b,k;long long int c;
    cin >> n >> m >>k;
    vector<pair<int,long long int> >adj[n+1];
    
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<long long int , int > > pq;
    int count[n+1]={0};int x =0;
    pq.push({0,1});
    while(! pq.empty()){
        long long int dis = (pq.top().first)*(-1);
        int node = pq.top().second;
        pq.pop();
        if(count[node] > k)
        continue;
        
        if(node == n){
            x++;
            cout << dis << " ";
            if(x ==k)
              break;
        }
        count[node]++;
        
            for(auto child : adj[node]){
                
                if(count[child.first] >= k)
                continue;
                pq.push({(-1)*(dis + child.second),child.first});
            }
    
    }
    
    return 0;
}
