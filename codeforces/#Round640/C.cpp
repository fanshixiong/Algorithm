#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], f[maxn];
void solve(){
    int n, k; cin >> n >> k;
    if(k % (n - 1) == 0){
        cout << k / (n - 1) * n - 1 << endl;
    }
    else{
        cout << k / (n - 1) * n + k % (n - 1) << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}