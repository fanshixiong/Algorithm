#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

int nxt[maxn][26];
void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int vis[26];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++){
        vis[t[i] - 'a'] = 1;
    }
    for (int i = 0; i < n; i++){
        vis[s[i] - 'a'] = 0;
    }
    for (int i = 0; i < 26; i++){
        if(vis[i]){
            cout << -1 << endl;
            return;
        }
    }

    //initial
    for (int i = 0; i < 26; i++)
        nxt[n][i] = -1;
    for (int i = n - 1; i >= 0; i--){
        for (int c = 0; c < 26; c++){
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    int cur = 0, ans = 1;
    for (int i = 0; i < m; i++){
        cur = nxt[cur][t[i] - 'a'];
        if(cur == -1){
            ans++;
            cur = 0;
            i--;
        }
        else{
            cur++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}