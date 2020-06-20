//Problem Link :- https://cses.fi/problemset/task/1751

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j,count,x;
    cin >> n;
    int arr[n+1];
    bool used[n+1]={false};
    long int succ[n+1]={0};
    for(i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(i=1;i<=n;i++){
        if(!used[i]){
            int a = i;
            vector<int> cycle;
            while(succ[a] == 0 && used[a]==false){
                cycle.push_back(a);
                used[a]=true;
                a=arr[a];
            }
            cycle.push_back(a);int l= cycle.size();
            if(succ[a]==0){
                 x = cycle[l-1];
                for(j=0;j<l;j++){
                    if(cycle[j] == x)
                    break;
                    succ[cycle[j]]=l-j-1;
                }
                 count = l-j-1;
                for(int y = j;y<l-1;y++){
                    succ[cycle[y]]=count;
                }
            }
            else{
                 count = 1;  x = cycle[l-1];
                for(j=l-2;j>=0;j--){
                    succ[cycle[j]]= succ[x]+count;
                    count++;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        cout << succ[i] << " ";
    }
    return 0;
}
