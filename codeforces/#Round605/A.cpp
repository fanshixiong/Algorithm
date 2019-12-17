#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a[3];
    for(int i=0; i<3; i++)
        cin >> a[i];
    sort(a, a+3);
    if(a[0]+1 <= a[2]){
        a[0]++;
    }
    if(a[2]-1 >= a[0])
        a[2]--;
    cout <<2*abs(a[0]-a[2]) << endl;
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