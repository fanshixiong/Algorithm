#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s;cin >> s;
    int ans = 0;
   
    for (int i = 26; i >= 1; i--){ 
        for (int p = 1; p < 100; p++){
            for (int j = 0; j < s.size(); j++){
                if (s[j] != i + 'a')
                    continue;
                if (j > 0 && s[j - 1] == i + 'a' - 1){
                    s.erase(j, 1);
                    ans++;
                    break;
                }
                if (j < s.size() - 1 && s[j + 1] == i + 'a' - 1){
                    s.erase(j, 1);
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}