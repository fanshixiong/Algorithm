#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp1[30], dp2[30][30];
int main(){
    ios_base::sync_with_stdio(0);
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++){
        char c = s[i] - 'a';
        for (int j = 0; j < 26; j++)
            dp2[j][c] += dp1[j];
        dp1[c]++;
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++){
        ans = max(ans, dp1[i]);
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++)
            ans = max(ans, dp2[i][j]);
    };
    cout << ans << endl;
    return 0;
}