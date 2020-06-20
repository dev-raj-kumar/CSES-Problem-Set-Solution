//Problem link :- https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,i,j,k,q;long long int w;
    cin >> n >> m >>q;

    long long int dis[n+1][n+1];
    for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
       dis[i][j]= 1e18;
       }
       dis[i][i]=0;
   }
    for(i=1;i<=m;i++){
        cin >> a >> b >> w;
        dis[a][b]=min(dis[a][b],w);
        dis[b][a]=min(dis[b][a],w);
    }
   
   
   for(k=1;k<=n;k++){
       for(i=1;i<=n;i++){
           for(j=1;j<=n;j++){
               dis[i][j] = min(dis[i][k] + dis[k][j] , dis[i][j]);
           }
       }
   }
    for(k=1;k<=q;k++){
        cin >> a>> b;
        if(dis[a][b] != (long int)1e18)
    cout << dis[a][b] << "\n";
    else
    cout << "-1\n";
    }
    return 0;
}
