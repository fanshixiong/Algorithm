#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    int q, x;
    cin >> q >> x;
    unordered_map<int, int> mp;
    int ans = 0;
    while(q--){
        int num;
        cin >> num;
        mp[num % x]++;
        while(mp[ans])
            ans++;
        while(mp[ans%x] > 1){
            mp[ans%x]--;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}