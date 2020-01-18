#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    ll l = 0, r = 0, n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'L')
            l++;
        if(s[i] == 'R')
            r++;
    }
    cout << r + l + 1 << endl;
    return 0;
}