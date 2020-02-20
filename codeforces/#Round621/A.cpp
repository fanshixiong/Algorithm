#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n, t;
    cin >> n >> t;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if(i == 0){
            ans += x;
            continue;
        }
        if (t >= x * i){
            t -= x * i;
            ans += x;
        }
        else if(t < x*i){
            int tmp = t / i;
            //cout <<i << " "<< t<< " " << tmp << "SSS"<<endl;
            if (tmp <= x){
                ans += tmp; t -= tmp*i;
            }
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
/*
1
6 16
8 2 1 3 3 3
*/