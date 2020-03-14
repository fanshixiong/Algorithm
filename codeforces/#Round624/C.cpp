#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int p[maxn], cnt[maxn];
void solve(){
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    for(int i = 0; i < m; i++){
        cin >> p[i];
        cnt[p[i]]++;
    }
    for (int i = n - 1; i > 0; i--){
        cnt[i] += cnt[i + 1];
    }
    int chart[27];
    memset(chart, 0, sizeof(chart));
    for (int i = 0; i < n; i++){
        //cout << cnt[i+1] << " ";
        chart[s[i] - 'a'] += (cnt[i+1]+1);
    }
    for (int i = 0; i < 26; i++){
        cout << chart[i] << " ";
    }
    cout << endl;
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