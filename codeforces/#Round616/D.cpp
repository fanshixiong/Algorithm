#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int cnt[30][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int q;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a'][i]++;
        if(i>=1){
            for (int j = 0; j < 26; j++){
                cnt[j][i] += cnt[j][i - 1];
            }
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l==r){
            cout << "YES" << endl;
            continue;
        }
        if(s[l]!=s[r]){
            cout << "YES" << endl;
            continue;
        }
        int c = 0;
        for (int i = 0; i < 26; i++){
            int R = cnt[i][r];
            int L = l == 0 ? 0 : cnt[i][l - 1];
            if(R-L>0)
                c++;
        }
        if(c>=3){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}