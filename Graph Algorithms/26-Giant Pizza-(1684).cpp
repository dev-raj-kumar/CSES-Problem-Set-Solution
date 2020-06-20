//Problem Link :- https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<int> tadj[200005];
bool used[200005];
stack<int> s;
int order[200005];
 
void dfs(int a){
    used[a]=true;
    for(auto x : adj[a]){
        if(! used[x])
        dfs(x);
    }
    s.push(a);
}
void tdfs(int a ,int val){
    order[a]=val;
    for(auto x : tadj[a]){
        if(order[x] == -1)
        tdfs(x,val);
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m,i,a,b;char c1,c2;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> c1 >> a >> c2 >>b;
        if(c1 == '-' && c2 == '-'){
            adj[2*a].push_back(2*b + 1);
            tadj[2*b + 1].push_back(2*a);
            adj[2*b].push_back(2*a + 1);
            tadj[2*a + 1].push_back(2*b);
        }
        else if(c1 == '-' && c2 == '+'){
            adj[2*a].push_back(2*b);
            tadj[2*b].push_back(2*a);
            adj[2*b + 1].push_back(2*a + 1);
            tadj[2*a + 1].push_back(2*b +1);
        }
        else if(c1 == '+' && c2 == '-'){
            adj[2*a +1].push_back(2*b +1);
            tadj[2*b +1].push_back(2*a +1);
            adj[2*b].push_back(2*a);
            tadj[2*a].push_back(2*b);
        }
        else if(c1 == '+' && c2 == '+'){
            adj[2*a +1].push_back(2*b);
            tadj[2*b].push_back(2*a +1);
            adj[2*b + 1].push_back(2*a);
            tadj[2*a].push_back(2*b +1);
        }
    }
    for(i=1;i<=(2*m)+1;i++){
        order[i]=-1;
        if(! used[i])
        dfs(i);
    }
    int j = 1;
    while(! s.empty()){
        int node = s.top();
        s.pop();
        if(order[node] == -1){
        tdfs(node,j);
        j++;
        }
    }
    bool arr[m+1]={false};int f = 0;
    for(i=2;i<=(2*m);i += 2){
        if(order[i] == order[i+1]){
            f=1;
            break;
        }
        else
        arr[i/2] = order[i] > order[i+1];
    }
    if(f)
    cout << "IMPOSSIBLE";
    else{
        for(i=1;i<=m;i++){
            if(arr[i])
            cout << "+ ";
            else
            cout << "- ";
        }
    }
    return 0;
}
