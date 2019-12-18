#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i=0; i<k; i++){
        char c;
        cin >> c;
        mp[c] = 1;
    }
    ll res = 0, i=0;
    while(i<n){
        while(i<n && !mp[s[i]])
            i++;
        ll l=i, r=0;
        while(i<n && mp[s[i]])
            i++;
        r = i;
        ll ct = r-l;
        res += (1+ct)*ct/2;
    }
    cout << res << endl;
    return 0;
}