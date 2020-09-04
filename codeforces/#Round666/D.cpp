#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int maxPile = *max_element(a.begin(), a.end());
    int sumStones = accumulate(a.begin(), a.end(), 0);

    if(maxPile*2 <= sumStones && ((sumStones & 1) == 0)) cout << "HL" << endl;
    else cout << "T" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}