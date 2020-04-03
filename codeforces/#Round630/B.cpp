#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int c[maxn], col[1010];
int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve(){
    int n;
    cin >> n;
    map<int, int> p;
    p.clear();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        for (int j = 0; j < 11; j++){
            if(c[i] % prime[j] == 0){
                if(!p[prime[j]]){
                    p[prime[j]] = ++ cnt;
                }
                //cout << i << " " << c[i] << " "<< prime[j] << endl;
                col[i] = p[prime[j]];
                break;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++){
        cout << col[i] << " ";
    }
    cout << endl;
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