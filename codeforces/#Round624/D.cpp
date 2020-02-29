#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll> 
const int maxn = 2e5 + 10;
ll a[maxn], t[maxn];
map<ll, ll> fa;
pll q[maxn];
bool cmp(pll &a, pll &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

ll find(ll x){
    return fa[x] == 0 ? x : fa[x] = find(fa[x]);
}
void unit(ll x, ll y){
    x = find(x), y = find(y);
    if(x != y)
        fa[x] = y;
}
int main(){
    int n;

    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    for (int i = 0; i<n; i++){
        cin >> t[i];
        q[i].first = a[i];
        q[i].second = t[i];
    }
    sort(q, q + n, cmp);
    /*9for (int i = 0; i < n; i++){
        cout << q[i].first << " " << q[i].second << endl;
    }*/
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll x = find(q[i].first);
        ans += (x - q[i].first) * q[i].second;
        unit(x, x + 1);
    }
    cout << ans << endl;
    return 0;
}