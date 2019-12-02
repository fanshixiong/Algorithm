#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int a[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    map<int, int> H;
    int d = 1;
    while(d <= n){
        H[d]=1;
        d *= 2;
    }
    multiset<int> m;
    long long res = 0;
    for(int i=n; i>=1; i--){
        if(a[i]==-1)
            break;
        m.insert(a[i]);
        if(H[i]){
            res += *m.begin();
            m.erase(m.begin());
        }
    }
    cout << res << endl;
    return 0;
}