#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a[3];
    bool b=0;
    
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    //cout <<min(a[0]+a[1], (a[0]+a[1]+a[2])/2) << endl;
    int tp = a[0]/2;
    int res = a[0];
    a[2] -= a[0];
    a[0]=0;
    int t = min(a[1], a[2]);
    res += t;
    a[1]-=t;
    a[2]-=t;
    sort(a, a+3);
    if(a[0]+a[1]+a[2] > 1) b=1;
    if(b)
        cout << res+tp <<endl;
    else{
        cout << res << endl;
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