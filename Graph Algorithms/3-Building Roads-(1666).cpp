//Problem Link :- https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
 
using namespace std;
int par[100005];
int siz[100005];
 
int fin(int a){
    vector<int> vec;
    while(a != par[a]){
        vec.push_back(a);
        a=par[a];
    }
    for(int i =0;i<vec.size();i++)
    par[vec[i]]=a;
    
    return a;
}
void uni(int a ,int b){
    int x = fin(a);
    int y = fin(b);
    if(x==y)
    return;
    
    if(siz[x] > siz[y]){
        par[y]=x;
        siz[x] += siz[y];
    }
    else{
        par[x]=y;
        siz[y] += siz[x];
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,u,v;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        par[i]= i;
        siz[i] = 1;
    }
    for(i=1;i<=m;i++){
        cin >> u >> v;
        uni(u,v);
    }
    vector<int> vec;
    for(i=1;i<=n;i++){
        if(i == par[i])
        vec.push_back(i);
    }
    cout << (vec.size()-1) << "\n";
    for(i=0;i< vec.size()-1;i++)
    cout << vec[i] << " " << vec[i+1] << "\n";
    return 0;
}
