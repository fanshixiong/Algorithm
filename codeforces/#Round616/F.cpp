#include<bits/stdc++.h>
using namespace std;
const int maxn = 30100;
int n, k;
bool flg[maxn];
void reset(){
    cout << "R" << endl;
}
bool query(int x){
    cout << "? " << x+1 << endl;
    string s;
    cin >> s;
    if(s[0] == 'Y')
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i <= n; i++){
        flg[i] = true;
    }
    if (k == 1){
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                reset();
                query(i);
                if (query(j))
                    flg[j] = false;
            }
        }
    }
    else{
        int block = k / 2;
        int m = n / block;
        for (int jump = 1; jump < m; jump++){
            for (int start = 0; start < jump && start + jump < m; start++){
                reset();
                for (int i = start; i < m; i += jump){
                    for (int x = i * block; x < (i + 1) * block; x++){
                        if(query(x))
                            flg[x] = false;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if(flg[i])ans++;
    cout << "! " << ans << endl;
    return 0;
}