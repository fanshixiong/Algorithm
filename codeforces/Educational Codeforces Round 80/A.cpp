#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int ma = sqrt(d) + 10, i;
        for (i = 0; i < ma; i++){
            if(i + (d+i)/(i+1) <= n)
                break;
        }
        cout << (i < ma ? "YES" : "NO") << endl;
    }
    return 0;
}