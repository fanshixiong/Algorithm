#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
double fac[maxn];
int main(){
    //ios_base::sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        fac[i] = fac[i - 1] + (double)1 / i;
    }
    printf("%lf", fac[n]);
    return 0;
}