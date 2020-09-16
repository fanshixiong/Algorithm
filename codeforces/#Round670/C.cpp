#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int ans[maxn];
void solve(){
    int n;
    cin >> n;
    int p = 0;
    for (int i = 1; i < n; i++){
        int a, b;
        cout << "? " << p+1 << " " << i+1 << endl;
        cin >> a;
        cout << "? " << i+1 << " " << p+1 << endl;
        cin >> b;
        if(a < b){
            ans[i] = b;
        }else{
            ans[p] = a;
            p = i;
        }
    }
    ans[p] = n;
    cout << "! ";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    IOS; int t=1;
    while(t--){
        solve();
    }
    return 0;
}