#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    if(n % 4){
        cout << "NO" << endl;
        return;
    }
    
    ll odds = 0, evens = 0;
    vector<int> a;
    for (int i = 1; i <= n / 2; i++){
        a.push_back(i * 2);
        evens += i * 2;
    }
    for (int i = 1; i <= n / 2 - 1; i++){
        a.push_back(2 * i - 1);
        odds += 2 * i - 1;
    }
    if((evens - odds) % 2){
        cout << "YES" << endl;
        for(auto x : a) cout << x << " ";
        cout << evens - odds << endl;
        return;
    }
    cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}