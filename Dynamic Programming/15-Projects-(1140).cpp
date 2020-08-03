//Problem Link :- https://cses.fi/problemset/task/1140/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,a,b,c;
    cin >> n;
    long long int dp[n+1]={0};
    vector<tuple<int,int,int> > vec;
    vec.push_back(make_tuple(0,0,0));
    for(i=1;i<=n;i++){
        cin >> a >> b >> c;
        vec.push_back(make_tuple(b,a,c));
    }
    sort(vec.begin(),vec.end());int pp = 0;tuple<int,int,int> tp;
    for(i=1;i<=n;i++){
        tp = make_tuple(get<1>(vec[i]),0,0);
        int id = lower_bound(vec.begin()+1,vec.begin()+i,tp)-vec.begin();
        id--;
        if(id < i && id>=0){
            dp[i] = max(dp[i-1],dp[id]+get<2>(vec[i]));
        }
    }
    cout << dp[n] << "\n";   
}
