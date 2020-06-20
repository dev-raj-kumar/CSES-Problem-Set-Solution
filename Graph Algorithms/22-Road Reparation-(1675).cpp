//Problem Link :- https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
using namespace std;
 
int par[100005];
struct edge{
    int a,b;
    long long int c;
};
bool comp(struct edge a , struct edge b){
    if(a.c < b.c)
    return true;
    else
    return false;
}
int find(int a){
    int b = a;
    while(par[a] != a)
    a=par[a];
    par[b]=par[a];
    return par[b];
}
void uni(int a , int b){
    par[a]=b;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,x,y; long long int w;
    cin >> n >> m;
    
        for(i=1;i<=n;i++)
             par[i]=i;
         struct edge arr[m];
         for(i=0;i<m;i++){
             cin >> arr[i].a >> arr[i].b >> arr[i].c;
          }
         sort(arr,arr+m,comp);
        long long int cost = 0;
         for(i=0;i<m;i++){
             x = find(arr[i].a);
             y = find(arr[i].b);
             if(x != y){
                 cost += arr[i].c;
                 uni(x,y);
            }
         }
         int f = 0;
         for(i=1;i<=n;i++){
             if(par[i]==i){
             f++;
             if(f==2)
             break;
             }
         }
         if(f<=1)
        cout << cost;
        else
        cout << "IMPOSSIBLE";
    
    return 0;
}
