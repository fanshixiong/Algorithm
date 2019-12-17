#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
vector<int> G[2][maxn];
int dp[maxn], val[2][maxn][maxn], sz[2][maxn], l[2][maxn], r[2][maxn];
int n;
void dfs(int _, int x){
    if(x != 1) 
        sz[_][x] = 1;
    for(int i=0; i<G[_][x].size(); i++){
        int v = G[_][x][i];
        dfs(_, v);
        l[_][x] = min(l[_][x], l[_][v]);
        r[_][x] = max(r[_][x], r[_][v]);
        sz[_][x] += sz[_][v];
    }
    val[_][l[_][x]][r[_][x]] = max(val[_][l[_][x]][r[_][x]], sz[_][x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int _=0; _<2; _++){
        int a;
        cin >> a;
        for(int i=1; i<=a; i++){
            r[_][i] = 0;
            l[_][i] = a+1;
        }
        for(int i=1; i<a; i++){
            int x;
            cin >> x;
            G[_][x].push_back(i+1);
        }
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            l[_][x] = r[_][x] = i;
        }
        dfs(_, 1);
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[j] = max(dp[j], dp[i-1] + max(val[0][i][j], val[1][i][j]));
        }
    }
    cout << dp[n] << endl;
    return 0;
}