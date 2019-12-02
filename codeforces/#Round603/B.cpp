#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
string s[maxn];
int n, ans;
map<string, int> Hp;
void change(int x){
    Hp[s[x]]--;
    for(int i=0;i<s[x].size();i++){
        char o = s[x][i];
        for(int j=0;j<10;j++){
            char c = '0'+j;
            s[x][i]=c;
            if(!Hp[s[x]]){
                ans++;
                Hp[s[x]]=1;
                return;
            }
        }
        s[x][i]=o;
    }
}
void solve(){
    Hp.clear();
    ans = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        Hp[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(Hp[s[i]]>1){
            change(i);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}