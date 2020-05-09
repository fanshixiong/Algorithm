#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int f[40];
void solve(){
    int n; cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 30; i++) f[i] = f[i - 1] << 1;
    ll a = f[n], b = 0;
    for (int i = 1; i < n / 2; i++) a += f[i];
    for (int i = n / 2; i < n; i++) b += f[i];
    cout << abs(a - b) << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
8
2
4
6
8
10
12
20
30
*/