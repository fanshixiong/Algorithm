#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 100 + 10;
int a[maxn], b[maxn];
void solve1(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> num;
    for (int i = 0; i < n; i++){
        if(a[i] == 0) num.push_back(0); 
        if(a[i] == 1) {if(i == 0 || a[i-1] == 0) num.push_back(1); }
        // cout << i << " " << a[i] << " " << num.size() << endl;
    }
    // for (auto x : num) cout << x << " "; cout << endl;

    n = num.size();
    int cnt = 0, ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) cnt += (num[i] & 1);
    
    if(cnt == 1){
        cout << 0 << endl;  return;
    }

    for (int l = 0; l + cnt - 1 < n; l++){
        int r = l + cnt - 1;
        int res = 0;

        vector<int> c0, c1;
        for (int i = 0; i < n; i++){
            if(i >= l && i <= r) {if(num[i] == 0) c0.push_back(i);}
            else {
                if(num[i] == 1) c1.push_back(i);
            }
        }
        for (int i = 0; i < c1.size(); i++){
            res += abs(c1[i] - c0[i]);
        }
        // cout << l << " " << r << " " << res << endl;
        ans = min(ans, res);
    }

    cout << ans << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++){ 
        cin >> a[i]; 
        if(a[i]) num.push_back(i);
    }

    cout << num.back() - num[0] - 1 - num.size() + 2 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}