#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], vis[maxn];
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    if(s[0] != s[k-1]){  //不一样直接输出最后一份，肯定最大
        cout << s[k-1] << endl;
        return;
    }
    string ans = "";
    ans += s[0];
    if(s[k] == s[n-1]){  //一样均分
        int num = (n - k) / k;
        if((n-k) % k) num++; //有余数+1
        ans += s.substr(k, num);
    }
    else{ //不一样分给第一组
        ans += s.substr(k, n);
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}