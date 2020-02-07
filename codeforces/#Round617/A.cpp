#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n;
    cin >> n;
    int x;
    int odds = 0, evens = 0, sum = 0;
    for (int i = 0; i < n; i ++){
        cin >> x;
        if(x & 1)
            odds++, sum += 1;
        else
            evens++, sum += 0;
    }
    //cout << sum << " " << odds << " " << evens << endl;
    if(sum & 1){
        cout << "YES" << endl;
        return;
    }
    if(odds && evens){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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