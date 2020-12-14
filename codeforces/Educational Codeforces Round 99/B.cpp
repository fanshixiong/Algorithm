#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e6 + 10;
int a[maxn][2];
void solve(){
    int n; cin >> n;

    int sums = 0, i = 1;
    while(sums < n){
        sums += i++;
    }

    if(sums == n){
        cout << i - 1 << endl;
        return;
    }

    for (int p = 1; p <= i; p++){
        if(sums - (p+1) == n){
            cout << i - 1 << endl;
            return;
        }
    }
    cout << i << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}