#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int x, y, m, n; cin >> n >> m >> x >> y;
    int single = 0, doub = 0;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++){
            if(s[j] == '.'){
                if(j+1 < m && s[j+1] == '.'){
                    doub++;
                    s[j] = s[j + 1] = '*';
                }
                else{
                    single++;
                    s[j] = '*';
                }
            }
        }
    }

    y = min(y, 2 * x);
    cout << single * x + doub * y << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}