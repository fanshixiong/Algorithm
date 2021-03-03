/*
https://ac.nowcoder.com/acm/problem/22494
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int a[maxn], tot = 0, cnt;
int l[maxn], r[maxn], w[maxn], ans[maxn];
vector<int> G[maxn];

void dfs(int u){
    if(u == 0) return;
    a[++tot] = w[u];
    dfs(r[u]); dfs(l[u]);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i]; 
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    dfs(1);
    ans[++cnt] = a[1];
    // 最长上升子序列贪心解法
    for(int i = 2; i <= n; i++){
        if(a[i] > ans[cnt]) ans[++cnt] = a[i];
        else{
            int t = lower_bound(ans + 1, ans + 1 + cnt, a[i]) - ans;
            ans[t] = a[i];
        }
    }
    cout << cnt << endl;
    return 0;
}