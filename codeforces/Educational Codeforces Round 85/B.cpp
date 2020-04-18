#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
bool cmp(int a, int b){ return a > b; }
void solve(){
    int n, x; cin >> n >> x;
    int sum = 0;
    int i, j = 0;
    for(i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    for(i = 1; i <=n; i++){
        if(a[i] >= x) sum += a[i] - x;
        else{ j = i; break;}
    }
    if(j == 0){
        cout << n << endl;
        return;
    }
    for(i = j; i <= n; i++){
        if(sum >= x - a[i]) sum -= x - a[i];
        else break;
    }
    cout << i - 1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}