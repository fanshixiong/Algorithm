#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 10;
const int mod = 1e9 + 7;
int m, n, mx = 0;
int l[maxn], r[maxn], a[maxn];
vector<int> v[maxn];
ll ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        int h, f;
        cin >> f >> h;
        v[f].push_back(h);
    }
    for (int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            l[j] = r[j] = 0;
        }
        for (int j = 1; j <= i; j++){
            l[a[j]]++;
        }
        for (int j = i + 1; j <= n; j++){
            r[a[j]]++;
        }
        int ok = i == 0, num = i != 0;
        ll s = 1;
        for(auto x : v[a[i]]){
            if(x == l[a[i]]){
                ok = 1; break;
            }
        }

        if(!ok)  continue;

        for (int j = 1; j <= n; j++){
            int x = 0, y = 0, sz = v[j].size();
            while(x < sz && v[j][x] <= l[j]) x++;
            while(y < sz && v[j][y] <= r[j]) y++;
            if(j == a[i]){  
                x = 0;  y -= (r[j] >= l[j]);
            }
            if(x + y == 0) continue;
            if(x > y) swap(x, y);
            if(!x){
                num ++; s = s * y % mod;
            }
            else if(y == 1){
                num ++; s = s * 2 % mod;
            }
            else{
                num += 2; s = s * x * (y - 1) % mod;
            }
        }
        
        if(num > mx){
            mx = num; ans = 0;
        }
        if(num == mx){
            ans = (ans + s) % mod;
        }
    }

    cout << mx << " " << ans << endl;
    return 0;
}