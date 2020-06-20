//Problem Link :- https://cses.fi/problemset/task/1678

#include <bits/stdc++.h>
using namespace std;
 
 bool used[100005];
 vector<int>adj[100005];
 int n,m;int cc;
 vector<int> vec;
 vector<int> vec1;
 int f;
 
 bool cycle(int a,int p){
     used[a]=true;
    vec.push_back(a);
    vec1.push_back(a);
     for(auto x : adj[a]){
         if(!used[x]){
             if(cycle(x,a))
             return true;
         }
         else{
             cc=x;
             vec.push_back(x);
             sort(vec1.begin(),vec1.end());
             if(binary_search(vec1.begin(),vec1.end(),x)){
                 f=1;
             }
             return true;
         }
     }
     vec.pop_back();
     vec1.pop_back();
     return false;
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
    }
    
    for(i=1;i<=n;i++){
        if(!used[i])
        {   f=0;
           if(cycle(i,0) && f){
               int ii;
               for(ii=0;ii<vec.size();ii++)
                 if(vec[ii]==cc){
                    j=ii;
                    break;
                   }
                      cout << (vec.size()-ii) <<"\n";
                      for(ii=j;ii<vec.size();ii++)
                      cout << vec[ii] <<" ";
                      return 0;
                   }
           
           vec.clear();
           vec1.clear();
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
