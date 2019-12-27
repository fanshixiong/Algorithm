#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int a[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long b[3]={0};
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i%2] += a[i]/2 + a[i]%2;
        b[(i+1)%2] += a[i]/2;
    }
    cout << min(b[0], b[1]) << endl;
    return 0;
}   