#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n;
    cin >> n;
    int sum = 0, zero = 0;
    for (int i = 0; i<n; i++){
        int x;
        cin >> x;
        if(x==0)
            zero++, sum++;
        sum += x;
    }
    cout << (sum == 0 ? zero + 1 : zero) << endl;
    return;
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