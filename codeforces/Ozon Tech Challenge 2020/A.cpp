#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn], b[maxn];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
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