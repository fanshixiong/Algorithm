#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x++, y++;
    int area1 = b * (x - 1);
    int area2 = b * (a - x);
    int area3 = a * (y - 1);
    int area4 = a * (b - y);
    cout << max(max(area1, area2), max(area3, area4)) << endl;
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