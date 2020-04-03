#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if((x1 == x2 && (a | b)) || (y1 == y2) && (c | d)){ 
        cout << "NO" << endl;
        return;
    }
    int xx = b - a + x, yy = d - c + y;
    if(xx < x1 || xx > x2 || yy < y1 || yy > y2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}