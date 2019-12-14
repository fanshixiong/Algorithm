#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;
int a[maxn];
void solve(){
    int n;
    cin >> n;
    int g=0, s=0, b=0;
    bool flg=0;
    if(n/2 < 5)
        flg=1;
    g=1;
    for(int i=0; i<n; i++)
        cin >> a[i];
    int t = n/2;
    int maxt = 0;
    for(int i=t; i>0; i--){
        if(a[i] == a[i-1])
            continue;
        maxt = i-1;
        break;
    }
    int mint = 1;
    for(int i=1; i<=maxt; i++){
        if(a[i] == a[0]){
            g++;
            mint = i+1;
            continue;
        }
        if(a[i] == a[mint] ||  s<=g){ //error 1 : s<=1
            s++;
            mint = i;
            continue;
        }
        b++;
    }
    if(g<1 || s<2 || b<2 || g>=s || g>=b || s+g+b>t){
        flg=1;
    }
    if(flg){
        cout << 0 << " " << 0 << " " << 0 << endl;
    }
    else{
        cout << g << " " << s << " " << b << endl;
    }
    
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