#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;

int a[maxn*2];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    cout << abs(a[n-1] - a[n]) << endl;
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