#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(int a, int b){
    return abs(a) > abs(b);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), cmp);

    int cnt = 0;
    ll ans = 1;
    for (int i = 0; i < m; i++){
        if(a[i] < 0) cnt++;
        //cout << a[i] << " ";
        ans *= a[i];
    }

    if(m == n) {
        cout << ans << endl;
        return;
    }
    if(cnt & 1){
        //cout << endl << 1 << " ";
        ll t1 = ans, t2 = ans;
        bool flg = false, flg2 = false;
        for (int i = m - 1; i >= 0; i--){
            if(a[i] < 0){
                t1 /= a[i];
                flg = true;
                break;
            }
        }
        if(flg){
            for (int i = m; i < n; i++){
                if(a[i] >= 0){
                    flg2 = true;
                    t1 *= a[i];
                    break;
                }
            }
        }
        if(!flg || !flg2) t1 = ans;

        //cout << flg << " " << flg2 << " " << t1 << endl;
        flg = false;
        flg2 = false;
        for (int i = m - 1; i >= 0; i--){
            if(a[i] > 0){
                t2 /= a[i];
                flg = true;
                break;
            }
        }
        if(flg){
            for (int i = m; i < n; i++){
                if(a[i] < 0){
                    t2 *= a[i];
                    flg2 = true;
                    break;
                }
            }
        }
        if(!flg || !flg2) t2 = ans;
        //cout << ans << " " <<  t1 << " " << t2 << endl;
        cout << max(t1, max(ans, t2)) << endl;
    }
    else{
        cout << ans << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}