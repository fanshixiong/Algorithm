#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    map<string, int> mmp;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mmp[v[i]]++;
    }
    string tmp;
    int ans = 0;
    bool flg = 0;
    for (int i = 0; i < n; i++){
        string s = v[i];
        reverse(s.begin(),s.end());
        string rev = v[i];
        if(s == rev){
            if(!flg){
                tmp += s;
                ans += m;
                flg = 1;
            }
            mmp[v[i]] = 0;   
        }
    }
        
    string S;
    for (int i = 0; i<n; i++){
        string s = v[i];
        reverse(s.begin(),s.end());
        string rev = v[i];
        if(mmp[s]>0 && mmp[rev]>0){
            int cnt = min(mmp[s], mmp[rev]);
            mmp[s] -= cnt; mmp[rev] -= cnt;
            ans += (cnt * m * 2);
            while(cnt){
                S += s;
                cnt--;
            }
        }
    }
    cout << ans << endl;
    string str = S;
    reverse(S.begin(), S.end());
    cout << str + tmp + S << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}