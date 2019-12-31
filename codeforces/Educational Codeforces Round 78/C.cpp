#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int sum[maxn*2];
void solve(){
    int n;
    cin >> n;
    map<int, int> pos;
    pos[0] = 0; //往左全部吃完
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=n*2; i++){
        int a;
        cin >> a;
        if(a == 2)
            a = -1;     
        sum[i] = sum[i-1] + a;
        if(i <= n)
            pos[sum[i]] = i; 
    }
    int ans = n*2;
    for(int i=n; i<=n*2; i++){
        auto it = pos.find(sum[i]-sum[2*n]);
        if(it != pos.end()){
            ans = min(i-it->second, ans);
        }
    }
    cout << ans << endl;
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