//Problem Link :- https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,i,j; long long int c;
    cin >> n >> m;
    vector<pair<int,long long int > > adjs[n+1];
    vector<pair<int , long long int > > adje[n+1];
    vector<tuple<int , int , long long int > > edge;
    vector<long long int> diss(n+1,1e18);vector<long long int > dise(n+1,1e18);
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        adjs[a].push_back({b,c});
        adje[b].push_back({a,c});
        edge.push_back({a,b,c});
    }
    diss[1]=0;
    //all intermediatery diatance from the starting node
    priority_queue< pair<long long int , int > > pq;
    pq.push({0,1});
    while(!pq.empty()){
        long long int di = (pq.top().first)*(-1);
        int node = pq.top().second;
        pq.pop();
        if(di > diss[node])
        continue;
        for(auto child: adjs[node]){
            if(diss[child.first] > child.second + di){
                diss[child.first]= child.second + di;
                pq.push({(-1)*diss[child.first],child.first});
            }
        }
    }
    //All intermediattery distance from the nth node
    priority_queue<pair<long long int , int > >pqe;
    dise[n]=0;pqe.push({0,n});
    while(! pqe.empty()){
        long long int di = (pqe.top().first)*(-1);
        int node = pqe.top().second;
        pqe.pop();
        if(di > dise[node])
        continue;
        for(auto child: adje[node]){
            if(dise[child.first] > child.second + di){
                dise[child.first]= child.second + di;
                pqe.push({(-1)*dise[child.first],child.first});
            }
        }
    }
    long long int spath = 1e18;
    //taking half of each edge and finding the minimum
    for(i=0;i<edge.size();i++){
        tuple<int , int , long long int > tup = edge[i];
        spath = min(spath , diss[get<0>(tup)] + dise[get<1>(tup)] + (get<2>(tup))/2);
    }
    cout << spath;
   /* cout << "\n";
    for(i=1;i<=n;i++)
    cout << diss[i] << " ";
    cout << "\n";
    for(i=1;i<=n;i++)
    cout << dise[i] << " ";*/
    return 0;
}
