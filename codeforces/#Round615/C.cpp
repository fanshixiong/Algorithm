#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            v.push_back(i);
            n /= i;
        }
        if(v.size() == 2){
            if(n>i){
                cout << "YES" << endl;
                cout << v[0] << " " << v[1] << " " << n << endl;
                return;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }
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