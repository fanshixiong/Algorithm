#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 10;
void solve(){
    map<int, int> a;
    int n, s, k;
    cin >> n >> s >> k;
    for (int i = 0; i < k; i++){
        int x; cin >> x;
        a[x] = true;
    }
    int l = s, r = s;
    while(l){
        if(!a[l])
            break;
        l--;
    }
    while(r<=n){
        if(!a[r])
            break;
        r++;
    }
    //cout << l << " " << r << endl;
    if(!l)
        cout << abs(r - s) << endl;
    else if(r==n+1)
        cout << abs(l - s) << endl;
    else cout << min(abs(l - s), abs(r - s)) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("Ain.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}