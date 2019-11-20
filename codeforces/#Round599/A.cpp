#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[1010];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int tp = min(n-i, a[i]);
        ans=max(ans, tp);
    }
    cout<<ans<<endl;
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