#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn], dp[maxn];
void solve(){
    int n; cin >> n;
    memset(dp, 0x3f, sizeof dp);
    stack<int> st1, st2; //递增， 递减
    dp[n] = 0; st1.push(n); st2.push(n);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = n - 1; i >= 1; i--){
        while(st1.size() && a[st1.top()] > a[i]){
            dp[i] = min(dp[i], dp[st1.top()] + 1);
            st1.pop();
        }
        if(st1.size()){
            dp[i] = min(dp[i], dp[st1.top()] + 1);
            if(a[st1.top()] == a[i]) st1.pop();
        }
        st1.push(i);
        while(st2.size() && a[st2.top()] < a[i]){
            dp[i] = min(dp[i], dp[st2.top()] + 1);
            st2.pop();
        }
        if(st2.size()){
            dp[i] = min(dp[i], dp[st2.top()] + 1);
            if(a[st2.top()] == a[i]) st2.pop();
        }
        st2.push(i);
    }
    cout << dp[1] << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}