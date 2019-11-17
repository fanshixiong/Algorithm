#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int f[35];
    f[1]=f[2]=f[3]=1;
    for(int i=4; i<=n; i++)
        f[i] = f[i-1]+f[i-2]+f[i-3];
    cout << f[n] << endl;
    return 0;
}