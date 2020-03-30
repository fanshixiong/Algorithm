#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
ll cnt[maxn], sum[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(cnt));
    for (int i = 2; i < maxn; i++){
        cnt[i] = cnt[i - 1] + 1;
        sum[i] = sum[i - 1] + cnt[i];
    }
    while (t--)   {
        int n, k, i;
        cin >> n >> k;
        for (i = 2; i <= n; i++){
            if(sum[i] >= k) break;
        }
        int j = i; k -= sum[j-1];
        string s;
        //cout << j << " " << k << endl;
        for (int i = 0; i < n; i++) s += 'a';
        s[n - j] = 'b';
        s[n - k] = 'b';
        cout << s << endl;
    }
    return 0;
}