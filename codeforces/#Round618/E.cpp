#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
double a[maxn], len[maxn], mean[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = (double)x * 1.0;
    }
    for (int i = 1; i<=n; i++){
        mean[++p] = a[i];
        len[p] = 1;
        while(p > 1 && mean[p] < mean[p-1]){
            mean[p - 1] = (mean[p] * len[p] + mean[p - 1] * len[p - 1]) / (len[p - 1] + len[p]);
            len[p - 1] += len[p];
            p--;
        }
    }
    for (int i = 1; i <= p; i++){
        for (int j = 1; j <= len[i]; j++){
            cout << setprecision(12) << mean[i] << " ";
        }
    } 
    return 0;
}