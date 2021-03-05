#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
ll n, I, h, r;
ll a[maxn];
void solve(){
    cin >> n >> I >> h >> r;
    memset(a, 0, sizeof a);
    map<pi, int> p;
    for (int i = 0; i < r; i++){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(p.count({x, y})) continue;
        p[{x, y}]++;
        a[x+1]--, a[y]++;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        cout <<  sum + h << endl;
    }
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}