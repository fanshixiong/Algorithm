#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 10;
ll v[maxn];
int n, m;
vector<int> in, out, ans1, ans2;
vector<ll> ans3;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        v[x] += z;
        v[y] -= z;
    }
    for (int i = 1; i <= n; i++){
        if(v[i] > 0){
            out.push_back(i);
        }
        else if(v[i] < 0){
            in.push_back(i);
        }
    }
    int i = 0, j = 0;
    while(1){
        if(i == in.size() || j == out.size())
            break;
        ll value = min(v[out[j]], -v[in[i]]);
        ans1.push_back(out[j]);
        ans2.push_back(in[i]);
        ans3.push_back(value);
        v[in[i]] += value;
        v[out[j]] -= value;
        if(v[in[i]] == 0)
            i++;
        if(v[out[j]] == 0)
            j++;
    }
    cout << ans1.size() << endl;
    for (int i = 0; i < ans1.size(); i++){
        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
    }
        return 0;
}