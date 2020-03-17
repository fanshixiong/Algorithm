#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 4e4 + 10;
int n, m, k;
int a[maxn], b[maxn];
int p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int c = 0;
    for (int i = 1; i * i <= k; i++){
        if(k % i != 0)
            continue;
        p[c++] = i;
        if(i * i == k)
            continue;
        p[c++] = k / i;
    }
    ll ans = 0;
    for (int i = 0; i < c; i++){
        ll Count = 0, x = 0, y = 0;
        for (int j = 0; j < n; j++){
            if(a[j] == 1)
                Count++;
            else
                Count = 0;
            if(Count == p[i]){
                Count--;
                x++;
            }
        }
        Count = 0;
        for (int j = 0; j < m; j++){
            if(b[j] == 1)
                Count++;
            else
                Count = 0;
            if(Count == k / p[i]){
                Count--;
                y++;
            }
        }
        ans += x * y;
    }
    cout << ans << endl;
    return 0;
}