#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
int main(){
    ios_base::sync_with_stdio(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> v;
    for (int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back((x - 1) % (a + b) / a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++){
        if(k >= v[i]){
            ans++;
            k -= v[i];
        }
        else
            break;
    }
    cout << ans << endl;
    return 0;
}