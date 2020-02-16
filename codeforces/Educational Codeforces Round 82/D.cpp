#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

int a[70];  
void solve(){
    memset(a, 0, sizeof(a));
    ll n, sum = 0;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        ll x; cin >> x;
        for (int j = 0; j < 60; j++){
            if((x>>j)&1){
                a[j]++;
            }
        }
        sum += x;
    }
    if(sum < n){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < 60; i++){
        if((n>>i)&1){
            if(!a[i]){      
                for (int j = i + 1; j < 70; j++){
                    if(a[j]){
                        a[j]--;
                        int cur = j;
                        while(cur!=i){
                            cur--;
                            a[cur]++;
                            ans++;
                        }
                        a[cur]++;
                        break;
                    }
                }
            }
            a[i]--;
        }
        a[i + 1] += a[i] / 2;
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