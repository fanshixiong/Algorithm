#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
int a[maxn], pre[maxn], suf[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; i--){
        suf[i] = suf[i + 1] | a[i];
    }
    int ans = -1, pos = -1;
    for (int i = 1; i <= n; i++){
        int tp = (suf[i + 1] | a[i] | pre[i - 1]) - (suf[i + 1] | pre[i - 1]);
        if(tp > ans){
            ans = tp;
            pos = i;
        }
    }
    cout << a[pos] << " ";
    for (int i = 1; i <= n; i++){
        if(i == pos)
            continue;
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}