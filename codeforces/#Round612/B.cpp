#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<string> v(n + 1);
    map<string, int> mp;
    int ans = 0;
    for (int i = 0; i<n; i++){
        string s;
        cin >> s;
        mp[s]++;
        v[i] = s;
    }
    int tot = 'S' + 'E' + 'T';
    for (int i = 0; i < n; i++){
        string s1 = v[i];
        for (int j = i + 1; j < n; j++){
            string s2 = v[j], s3 = v[j];
            for (int p = 0; p < k; p++){
                if(s1[p] == s2[p])
                    s3[p] = s1[p];
                else
                    s3[p] = tot - s1[p] - s2[p];
            }
            if(mp[s3]){
                ans += mp[s3];
            }
        }
    }
    cout << ans/3 << endl;
    return 0;
}