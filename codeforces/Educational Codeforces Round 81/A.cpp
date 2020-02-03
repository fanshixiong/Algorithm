#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = n >> 1;
        if(n & 1){
            cout << 7;
            cnt--;
        }
        while(cnt--){
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}