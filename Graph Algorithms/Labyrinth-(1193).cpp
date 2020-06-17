//problem link :- https://cses.fi/problemset/task/1193
/*
   THIS CODE GIVES TLE FOR ONE CASE */
   
#include <bits/stdc++.h>
 
using namespace std;
char arr[1001][1001];
int dis[1001][1001];
int n;int m;
bool valid(int a , int b){
    if(a<1 || a>n || b<1 || b>m)
    return false;
    if(arr[a][b] == '#' || dis[a][b] != -1)
    return false;
    
    return true;
}
int main() {
   
ios_base :: sync_with_stdio(0);cin.tie(NULL); int i,j; 
    cin >> n >> m;
    int disx[] = { 1,-1,0,0};
    int disy[] = { 0,0,1,-1};
    string dir ="DURL";
     int sr,sc,er,ec;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> arr[i][j];
            dis[i][j]=-1;
            if(arr[i][j] == 'A'){
                sr = i;
                sc=j;
            }
            else if(arr[i][j] == 'B'){
                er=i;
                ec=j;
            }
        }
    }
    queue<pair< pair<int,int > , string> > q;
    int f = 0;string res = ""; 
   
    dis[sr][sc]=0;
    q.push({{sr,sc},""});
    while(! q.empty()){
        pair<int , int > curr = q.front().first;
        string s = q.front().second;
        q.pop();
        int x = curr.first; int y =curr.second;
        
        for(i=0;i<=3;i++){
            if(valid(x+disx[i],y+disy[i])){
                q.push({{x+disx[i],y+disy[i]},s+dir[i]});
                dis[x+disx[i]][y+disy[i]]=dis[x][y] + 1;
                if(arr[x+disx[i]][y+disy[i]] == 'B'){
                    f=1;
                    res= s+dir[i];
                    break;
                }
            }
        }
        if(f)
        break;
    }
    if(f){
        cout << "YES\n";
        cout << dis[er][ec] << "\n";
        cout << res;
    }
    else
    cout << "NO";
    
    return 0;
}
