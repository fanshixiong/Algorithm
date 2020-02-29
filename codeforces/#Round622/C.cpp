#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
ll n, l[maxn], r[maxn], h[maxn];
pair<int, int> s[maxn];
void solve(ll ans[]){
    int top = 0;
    ll cur = 0;
    s[top] = make_pair(0, 0);

    for (int i = 1; i <= n; i++){
        while(top && s[top].first > h[i]){
            cur -= (1ll * s[top].first * (s[top].second - s[top - 1].second));
            top--;
        }
        cur += (1ll * h[i] * (i - s[top].second));
        s[++top] = make_pair(h[i], i);
        ans[i] = cur;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    solve(l);
    reverse(h + 1, h + 1 + n);
    solve(r);
    reverse(h + 1, h + 1 + n);
    reverse(r + 1, r + 1 + n);
    
    ll ans = r[1], pos = 1;
    for (int i = 1; i <= n; i++){
        ll t = l[i] + r[i] - h[i];
        if(ans < t){
            ans = t;
            pos = i;
        }
    }
    
    ll res[n + 1]; res[pos] = h[pos];
    for (int i = pos - 1; i >= 1; i--){
        res[i] = min(res[i + 1], h[i]);
    }
    for (int i = pos + 1; i <= n; i++){
        res[i] = min(res[i - 1], h[i]);
    }

    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}