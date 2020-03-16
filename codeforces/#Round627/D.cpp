#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
ll a[maxn], b[maxn], c[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c, c + n);
    ll ans = 0;   
    for (int i = 0; i < n; i++){
        int pos = upper_bound(c + i + 1, c + n, -c[i]) - c;
        if(pos >= n)
            continue;
        ans += (n - pos);
    }
    cout << ans << endl;
    return 0;
}