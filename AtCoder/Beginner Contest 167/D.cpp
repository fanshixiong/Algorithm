//找循环节.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
ll a[maxn], v[maxn];
void solve(){
    ll n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll len = 0;
    v[1] = 1;
    queue<int> q;
    q.push(1);
    int tp = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int t = a[u];
        if(!v[t]){
            q.push(t);
            v[t] = v[u] + 1;
        }
        else{
            tp = v[t] - 1;
            len = v[u] - v[t] + 1;
            break;
        }
    }

    //cout << tp << len << endl;
    int tr = 1;
    if(k > tp + len) k = (k - tp) % len + tp; 

    for (int i = 0; i < k; i++) tr = a[tr];
    cout << tr << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}