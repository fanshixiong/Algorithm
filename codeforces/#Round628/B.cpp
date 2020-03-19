#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    map<int, int> v;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if(!v[x]){
            cnt++;
            v[x]++;
        }
    }
    cout << cnt << endl;
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