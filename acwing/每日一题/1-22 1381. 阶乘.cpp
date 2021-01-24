#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int MOD = 1e9;
void solve() {
    int n;
    cin >> n;
    long long fac = 1;
    for(int i = 1; i <= n; i++) {
        fac *= i;
        while(!(fac % 10)) fac /= 10;
        fac %= MOD;
    }
    cout << fac % 10 << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}