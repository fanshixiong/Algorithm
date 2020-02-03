#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    while(n--){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int ma = max(a, max(b, c));
        int cnt = abs(ma - a) + abs(ma - b) + abs(ma - c);
        int remain = n - cnt;
        if(remain >= 0 && remain % 3 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}