//Problem Link :- https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
using namespace std;
 
struct edge{
    int a , b; long long int c;
};
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,i,j; long long int c;
    cin >> n >> m;
    vector<edge> ed;
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        struct edge edg = {a,b,c};
        ed.push_back(edg);
    }
    int par[n+1];
    long long int dis[n+1];
    for(i=1;i<=n;i++){
        dis[i]=1e18;
        par[i]=-1;
    }
    dis[1]=0;
    int x;
    for(i=1;i<=n;i++){
        x=-1;
        for(int j=0;j<ed.size();j++){
            
                if(dis[ed[j].b] > dis[ed[j].a] + ed[j].c){
                    dis[ed[j].b] = dis[ed[j].a] + ed[j].c;
                    x=ed[j].b;
                    par[ed[j].b]= ed[j].a;
                } 
        }
    }
    if(x==-1)
    cout << "NO";
    else{
        vector<int> cycle;
        for(i=1;i<=n;i++)
        x=par[x];
        
        for(i=x;;i=par[i]){
            cycle.push_back(i);
            if(i==x && cycle.size() > 1)
            break;
        }
        reverse(cycle.begin(),cycle.end());
        cout << "YES\n";
        for(i=0;i<cycle.size();i++)
        cout << cycle[i] << " ";
    }
    return 0;
}
