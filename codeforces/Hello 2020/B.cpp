#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans = 0, all = 0;
    vector<int> MI, MX;
    for (int i = 0; i<n; i++){
        int x, a, flg=0;
        int mi = 0x3f3f3f3f3f, mx = 0;
        cin >> x;
        while(x--){
            cin >> a;
            if(a > mi && !flg){
                flg = 1;
            }
            mi = min(mi, a);
            mx = max(mx, a);
        }
        if(flg){
            ans += 1ll * n;
            all++;
        }
        else{
            MI.push_back(mi);
            MX.push_back(mx);
        }
    }
    sort(MI.begin(), MI.end());
    sort(MX.begin(), MX.end());
    int cnt = 0;
    for (int i = 0; i < MI.size(); i++){
        while(cnt<MI.size() && MI[cnt] < MX[i])
            cnt++;
        ans += 1ll * cnt + all;
    }
    cout << ans << endl;
    return 0;
}   