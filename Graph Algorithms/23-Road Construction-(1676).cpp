//Problem Link :- https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;
int par[100005];
int siz[100005];
 
int find(int a){
    vector<int> vec;
    while(par[a] != a){
        vec.push_back(a);
        a=par[a];
    }
    a=par[a];
    for(int i = 0;i<vec.size();i++)
    par[vec[i]]=a;
    
    return a;
}
int uni(int a , int b){
    if(siz[a] > siz[b]){
        siz[a] += siz[b];
        par[b]=a;
        return a;
    }
    else{
        siz[b] += siz[a];
        par[a]=b;
        return b;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,a,b;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        par[i]=i;
        siz[i]=1;
    }
    int sizeM = 1;
    int numC = n;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        if(x != y){
           int p =  uni(x,y);
            if(siz[p] > sizeM){
                sizeM = siz[p];
            }
            numC--;
        }
        cout << numC << " " << sizeM << "\n";
    }
    return 0;
}
