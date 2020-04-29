#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll ret[maxn];
void solve(){
    ll n; cin >> n;

    for(int i = 1; i < 30; i++){
        if(n % ret[i] == 0){
            cout << n / ret[i] << endl;
            return;
        }
    }
    return;
}
int main(){
    IOS; int t; cin >> t;
    memset(ret, 0, sizeof ret);
    ret[0] = ret[1] = 1;
    for(int i = 1; i <= 30; i++) ret[i] = ret[i - 1] * 2;
    for (int i = 1; i <= 30; i++) ret[i] += ret[i - 1];
    while (t--){
        solve();
    }
    return 0;
}