#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, k; cin >> n >> k;
    int n1 = n - (k - 1), n2 = n - (k - 1) * 2;
    if(n1 > 0 && n1 % 2 == 1){
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 1 << " ";
        cout << n1 << endl;
    }
    else if(n2 > 0 && n2 % 2 == 0){
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 2 << " ";
        cout << n2 << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
24
*/