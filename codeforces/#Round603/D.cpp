#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int far[maxn];
int find(int x){
    return far[x] == x ? x : far[x] = find(far[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1; i<=n+26; i++)
        far[i] = i;
    string s;
    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=0; j<s.size(); j++){
            far[find(i)] = far[find(n+s[j]-'a'+1)];
        }
    }
    set<int> st;
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!st.count(find(i))){
            ans++;
            st.insert(find(i));
        }
    }
    cout << ans << endl;
    return 0;
}