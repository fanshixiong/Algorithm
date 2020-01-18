#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ll a, b, cnt=0;
        cin >> a >> b;
        b++;
        while(b){
            cnt++;
            b /= 10;
        }
        ll ans = a * (cnt - 1);
        cout << ans << endl;
    }
    return 0;
}