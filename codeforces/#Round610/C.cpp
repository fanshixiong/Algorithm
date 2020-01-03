#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
ll ti[maxn], eaOrha[maxn];
vector<pair<ll, ll> > v;
void solve(){
        v.clear();
        int n, T, a, b;
        cin >> n >> T >> a >> b;
        int easy = 0, hard = 0;
        for (int i = 1; i <= n; i++){
            cin >> eaOrha[i];
            if(eaOrha[i]){
                hard++;
            }
            else
                easy++;
        }
        v.push_back({0, 0});
        for (int i = 1; i <= n; i++){
            cin >> ti[i];
            v.push_back({ti[i], eaOrha[i]});
        }
        sort(v.begin()+1, v.end());
        ll time1 = 0;
        v.push_back({T+1, -1});
        int ans = 0;
        for (int i = 0; i <= n; i++){
            if(i){
                if(v[i].second){
                    hard--;
                    time1 += b;
                }
                else{
                    easy--;
                    time1 += a;
                }
            }
            if((!i || i==n || v[i].first != v[i+1].first) && time1<=T && time1 < v[i+1].first){
                int re = v[i + 1].first - time1 - 1;
                int num1 = min(easy, re / a);
                re -= num1 * a;
                int num2 = min(hard, re / b);
                ans = max(ans, num1 + num2 + i);
            }

        }
        cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("Cin.txt", "r", stdin);
    //freopen("Cout.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    //system("pause");
   
    return 0;
}