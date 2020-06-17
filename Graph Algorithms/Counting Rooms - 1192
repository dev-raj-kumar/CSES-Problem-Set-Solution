// Problem link :- https://cses.fi/problemset/task/1192/

#include <bits/stdc++.h>
 
using namespace std;
 
int used[1001][1001];
int n;
int m;
int arr[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
 
bool isvalid(int,int);
void dfs(int x , int y , int id){
    used[x][y] = id;
    for(int i=0;i<=3;i++){
        if(isvalid(x + dx[i],y + dy[i]))
        dfs(x+dx[i] , y+dy[i] , id);
    }
}
 
bool isvalid(int x , int y){
    if(x < 1 || x > n || y < 1 || y > m)
    return false;
    if(used[x][y] || !arr[x][y])
    return false;
    
    return true;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int i,j;
    cin >> n >> m;
    char ch;int count = 0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> ch;
            if(ch == '#')
            arr[i][j]=0;
            else
            arr[i][j]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(arr[i][j] && !used[i][j]){
                count++;
                dfs(i,j,count);
            }
        }
    }
    cout << count << "\n";
    
    return 0;
}
