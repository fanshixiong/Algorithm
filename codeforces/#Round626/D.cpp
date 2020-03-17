#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int n, ans;
int a[maxn], b[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int k = 0; k < 25; k++){
        for (int j = 0; j < n; j++){
            b[j] = a[j] & ((1 << (k + 1)) - 1);
        }
        sort(b, b + n);

        int d = 1 << k;
        int cnt = 0, x = 0, y = 0, z = 0;
        for (int j = n - 1; j >= 0; j--){
            while(x<n && b[x] + b[j]<d) x++;
            while(y<n && b[y] + b[j]<2*d) y++;
            while(z<n && b[z] + b[j]<3*d) z++;

            cnt += max(0, min(j, y) - x); //
            cnt += max(0, j - z);        //不懂
        }

        if(cnt & 1)
            ans |= (1 << k);
    }
    cout << ans << endl;
    return 0;
}