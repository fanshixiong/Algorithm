/*
https://ac.nowcoder.com/discuss/582378?source_id=profile_create_nctrack&channel=-1
思维
*/

#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
const int maxn = 2e5 + 10;
const int mod = 1e9;
const ll INF = 1e10 + 7;
/*
int l[maxn], r[maxn], cost[maxn];

int n, x;
bool cmp(const int &a, const int &b){
    return r[a]-l[a] < r[b]-l[b];
}

int p[maxn];
void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i] >> cost[i];

    for(int i = 0; i < n; i++) p[i] = i;

    sort(p, p+n, cmp);
    int ans = 0x3f3f3f3f;
    for(int i = 0; i < n; i++){
        int x1 = p[i];
        int tar = x - (r[x1] - l[x1] + 1);
        int ll = x1+1, rr = n-1;
        int j = -1;
        while(ll <= rr){
            int mid = (ll + rr) / 2;
            if(r[mid]-l[mid]+1 >= tar){
                j = mid;
                rr = mid-1;
            }else ll = mid+1;
        }
        if(j == -1) continue;
        // cout << j << endl;
        while(j < n){
            // cout << tar << " " << j << endl;
            if(r[x1] < l[j] || r[j] < l[x1])ans = min(ans, cost[x1] + cost[j]);
            j++;
        }
    }
    if(ans == 0x3f3f3f3f) ans = -1;
    cout << ans << endl;
}
*/
struct node{
    int l,r;
    ll w;
};
 
vector<node> g[maxn];
 
bool cmp(node x,node y){
    return x.l<y.l;
}
 
void solve(){
    int n,x; cin>>n>>x;
    for(int i = 0; i < n; i++){
        int l,r,w;cin>>l>>r>>w;
        g[r-l+1].pb({l,r,w});
    }
    for(int i=1;i<x;i++) sort(g[i].begin(),g[i].end(),cmp);
    ll ans = INF;
    for(int len=1;len<x;len++){
        // debug(g[len].size());debug(g[x-len].size());
        ll minu=INF;
        auto u=g[len],v=g[x-len];
        for(int i=0,j=0;j<v.size();j++){
            // int l1=u[i].l,r1=u[i].r,l2=v[j].l,r2=v[j].r;
            while(i<u.size()&&u[i].r<v[j].l){
                minu=min(minu,u[i].w);
                i++;
            }
            if(minu!=INF) ans=min(ans,minu+v[j].w);
        }
    }
 
    if(ans==INF) cout<<"-1\n";
    else cout<<ans<<"\n";
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
/*
4 5
1 2 4
4 6 2
5 6 2
7 8 2

43 90
181 279 13
29 95 22
146 156 56
27 47 79
362 373 64
418 449 48
412 440 68
44 110 100
428 488 1
409 416 81
230 311 54
157 226 86
421 455 76
439 477 15
163 174 2
218 294 40
223 297 52
56 120 23
171 199 68
329 356 35
254 262 58
112 173 45
231 281 28
47 73 19
129 176 19
12 88 91
263 294 15
381 412 35
276 314 9
247 323 35
404 446 36
211 265 65
286 346 33
288 346 84
55 118 9
181 184 92
302 315 77
267 284 20
190 199 67
5 47 54
380 456 41
98 105 82
209 220 14
*/