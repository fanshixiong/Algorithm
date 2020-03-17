/*#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    memset(p, 0, sizeof(p));
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; i++){
        p[i] = s[i - 1] == ')' ? 1 : -1;
    }
    for (int i = 1; i <= n; i++){
        p[i] += p[i - 1];
    }
    if(p[n] != 0){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0, maxp = -1;
    bool flg = 0;
    for (int i = 1; i <= n; i++){
        maxp = max(maxp, p[i]);
        if(p[i] > 0)
            flg = 1;
        if(flg && p[i] == 0){
            //cout << i << " " << maxp << endl;
            ans += maxp * 2;
            flg = 0;maxp = 0;
        }
    }
    cout << ans << endl;
    return 0;
}*/
//右括号进栈，左括号出栈。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, l = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == ')')
            l++;
        else{
            l--;
            if(l >= 0)
                ans++;
        }
    }
    if(l != 0){
        cout << -1 << endl;
    }
    else{
        cout << ans * 2 << endl;
    }
    return 0;
}