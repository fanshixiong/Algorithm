/*
https://ac.nowcoder.com/discuss/586493
前缀和 +  01 trie
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;

int nxt[maxn * 32][2];
ll sz[maxn * 32];
int cnt = 1;
int n, k;
void insert(int x){
    int p = 1;
    for(int i = 30; i >= 0; i--){
        int c = x >> i & 1;
        if(!nxt[p][c]) nxt[p][c] = ++ cnt;
        p = nxt[p][c];
        sz[p]++;
    }
}
ll find(int x){
    int p = 1;
    ll res = 0;
    for(int i = 30; i >= 0; i--){
        int c = x >> i & 1;
        if(k >> i & 1)  p = nxt[p][c ^ 1]; //k的第i位为1，要从第i位为1开始找
        else  res += sz[nxt[p][c ^ 1]], p = nxt[p][c]; //否则从第i位为
    }

    res += sz[p];
    return res;
}

int a[maxn], pre[maxn];

ll ans;
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = a[i] ^ pre[i-1];

    for(int i = 1; i <= n; i++) insert(pre[i-1]), ans += find(pre[i]);

    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
/*
1 80 7
*/