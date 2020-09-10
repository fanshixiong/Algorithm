#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    int cnt1 = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]&1) cnt1++;
    }
    int cnt0 = n - cnt1;
    if (cnt0 >= n / 2){
        cout << cnt0 << endl;
        for (int i = 0; i < cnt0; i++) cout << 0 << " ";
        cout << endl;
    }else{
        cout << cnt1 - cnt1 % 2 << endl;
        for (int i = 0; i < cnt1 - cnt1 % 2; i++) cout << 1 << " ";
        cout << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}