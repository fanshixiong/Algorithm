#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> p;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        p[x]++;
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(p.count(x)) cnt++;
    }

    cout << cnt << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}