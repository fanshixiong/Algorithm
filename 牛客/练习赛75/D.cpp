#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pb push_back
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;

ll a[maxn];
ll n, k;
void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    sort(a, a + n);
    for(int i = 0; i < n; i++) pq.push(a[i]);

    ll ans;
    while((int)pq.size() > 1){
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        ans = x * y + k;
        pq.push(ans);
        if(ans >= a[n-1]) break;
    }
    if((int)pq.size() == 1){
        cout << pq.top() % mod << endl;
        return;
    }

    queue<ll> q;
    while(!pq.empty()){
        //cout << (int)pq.size() << " " << pq.empty() << endl;
        ll x = pq.top() % mod; pq.pop();

        //cout << (int)pq.size() << " " << pq.empty() << endl;
        q.push(x);
    }
    while((int)q.size() > 1){
        ll x = q.front(); q.pop();
        ll y = q.front(); q.pop();

        q.push((x * y % mod + k) % mod);
    }
    cout << q.front() << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}