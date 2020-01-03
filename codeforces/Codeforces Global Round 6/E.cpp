#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
ll a[maxn], ans;
int n, q;
map<pair<int, int>, int> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i];
    }
        cin >> q;
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        if(mp[make_pair(x, y)]){
            a[mp[make_pair(x, y)]]++;
            if(a[mp[make_pair(x, y)]] > 0){
                ans++;
            }
            mp[make_pair(x, y)] = 0;
        }
        if(z){
            mp[make_pair(x, y)] = z;
            a[z]--;
            if(a[z] >= 0){
                ans--;
            }

        }
        cout << ans << endl;
    }
    return 0;
}