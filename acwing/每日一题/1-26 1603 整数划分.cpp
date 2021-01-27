#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

int a[maxn];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int h1 = 0, h2 = 0;

    int i = 0;
    for(; i < n/2 ; i++) {
        h1 += a[i];
        h2 += a[i + n/2];
    }
    if(i < n) h2 += a[i + n/2];

    int jo = n % 2;

    cout<< jo << " " << h2 - h1;
}
int main(){
    solve();
}
