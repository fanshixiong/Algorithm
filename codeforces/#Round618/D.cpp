#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
map<pair<int, int>, int> H;
ll x[maxn], y[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll midx = 0, midy = 0;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        x[i] *= n, y[i] *= n;
        midx += x[i], midy += y[i];
        H[make_pair(x[i], y[i])] = 1;
    }
    midx /= n, midy /= n;
    for (int i = 0; i < n; i++){
        if(H[make_pair(2 * midx - x[i], 2 * midy - y[i])] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}