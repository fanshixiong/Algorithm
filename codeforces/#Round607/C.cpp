#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=1;
    while(s.size() < n){
        int len = s.size();
        for(int i=1; i<s[l-1]-'0'; i++){
            s += s.substr(l, len-l);
        }
        l++;
    }
    ll ans = s.size() % mod;
    while(l <= n){
        int x = s[l-1] - '0';
        ans = ((ans+(ans-l) * (x-1))%mod + mod) %mod; // error  未加 +mod 防止出现负数
        l++;
    }
    cout << ans%mod << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}