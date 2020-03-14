#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int r[maxn], p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int a = 0, b = 0 ;
    for (int i = 0; i < n; i++){
        cin >> r[i];
    }
    for (int i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] == 0 && r[i] == 1) a++;
        else if(p[i] == 1 && r[i] == 0) b++;
    }
    if(a == 0) cout << -1 << endl;
    else  cout << b / a + 1 << endl;
    return 0;
}