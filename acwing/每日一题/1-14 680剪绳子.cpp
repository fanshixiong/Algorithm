#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

int a[maxn],n,m;
bool check(double mid){
    int sum=0;
    for(int i = 0; i < n; i++){
        sum += a[i] / mid;
    }
    if(sum >= m) return true;
    return false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin>>a[i];
    double l = 0, r = 1e9;
    while(r - l > 1e-4)  {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    printf("%.2f\n",r);
    return 0;
}
