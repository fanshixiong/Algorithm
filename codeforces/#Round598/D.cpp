#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2010;
ll c[maxn], k[maxn], ax[maxn], ay[maxn];
int par[maxn];
struct node{
    int x, y;
    ll c;
    node(int x, int y, ll c):x(x), y(y), c(c){}
};
vector<node> city;
vector<node> ans_pot, ans_edg;
ll cnt=0;
bool cmp(node a, node b){
    return a.c < b.c;
}
int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        par[i] = i;
    for(int i=1; i<=n; i++){
        cin >> ax[i] >> ay[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=n; i++){
        cin >> k[i];
    }
    for(int i=1; i<=n; i++){
        city.push_back(node(0, i, c[i]));
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            city.push_back(node(i, j, (abs(ax[i]-ax[j])+abs(ay[i]-ay[j]))*(k[i]+k[j])));
        }
    }
    sort(city.begin(), city.end(), cmp);
    for(int i=0; i<city.size(); i++){
        ll cost = city[i].c;
        int x = city[i].x;
        int y = city[i].y;
        if(find(x) == find(y))
            continue;
        cnt += cost;
        if(x==0)
            ans_pot.push_back(city[i]);
        else
            ans_edg.push_back(city[i]);
        par[find(y)] = x;
    }
    cout << cnt << endl;
    cout << ans_pot.size() << endl;
    for(int i=0; i<ans_pot.size(); i++){
        cout << ans_pot[i].y << " ";
    }
    cout << endl << ans_edg.size() << endl;
    for(int i=0; i<ans_edg.size(); i++){
        cout << ans_edg[i].x << " " << ans_edg[i].y << endl;
    }
    return 0;
}