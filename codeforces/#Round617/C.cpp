#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0x3f3f3f3f;
    int ansl, ansr;

    int x = 0, y = 0;
    map<pair<int, int>, int> M;
    M[make_pair(0, 0)] = 0;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == 'R')
            x++;
        if(c == 'L')
            x--;
        if (c == 'U')
            y--;
        if(c == 'D')
            y++;
        if(M.count(make_pair(x, y))){
            if(ans > i - M[make_pair(x, y)]){
                ans = i - M[make_pair(x, y)];
                ansl = M[make_pair(x, y)];
                ansr = i;
            }
        }
        M[make_pair(x, y)] = i + 1;
    }
    if(ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ansl + 1 << " " << ansr + 1 << endl;
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