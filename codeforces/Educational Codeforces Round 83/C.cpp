#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[35], bit[35][64];
int n, k;
void getbit(int _){
    int cnt = 0;
    ll x = a[_];
    while(x){
        bit[_][cnt++] = x % k;
        x /= k;
    }
}
void solve(){
    memset(bit, 0, sizeof(bit));
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        getbit(i);
    }

    
    for (int i = 0; i < 64; i++){
        ll sum = 0;
        for (int j = 0; j < n; j++){
            sum += bit[j][i];
        }
        if(sum > 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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