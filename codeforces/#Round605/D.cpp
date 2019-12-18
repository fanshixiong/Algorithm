#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn], l[maxn], r[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        l[i] = r[i] = 1;
    }
    int res = 0;
    for(int i=n-1; i>0; i--){
        if(a[i]>a[i-1]) 
            l[i-1] = l[i]+1;
        res = max(l[i-1], res);
    }
    for(int i=0; i<n-1; i++){
        if(a[i]<a[i+1])
            r[i+1] = r[i]+1;
        res = max(r[i+1], res);
    }
    for(int i=1; i<n-1; i++){
        if(a[i-1] < a[i+1])
            res = max(l[i+1]+r[i-1], res);
    }
    cout << res << endl;
    return 0;
}