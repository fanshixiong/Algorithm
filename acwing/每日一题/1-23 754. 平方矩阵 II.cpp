#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << abs(i - j) + 1 << " ";
        cout << endl;
    }
    cout << endl;
}
int main(){
    IOS; int t;
    while(cin >> t && t){
        solve(t);
    }
    return 0;
}