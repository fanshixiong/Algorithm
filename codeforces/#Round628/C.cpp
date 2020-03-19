#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node{
    int x, y;
    int num;
}e[maxn];
int in[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int p = -1;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        e[i].x = x; e[i].y = y; e[i].num = -1;
        in[x]++; in[y]++;
        if(in[x] >= 3) p = x;
        if(in[y] >= 3) p = y;
    }
    if(p == -1){
        for (int i = 0; i < n - 1; i++){
            cout << i << endl;
        }
    }
    else{
        int cnt = 0;
        for (int i = 1; i < n; i++){
            if(cnt == 3) break;
            if(e[i].x == p || e[i].y == p){
                e[i].num = cnt++;
            }
        }
        for (int i = 1; i < n; i++){
            if(e[i].num == -1){
                cout << (cnt++) << endl;
            }
            else{
                cout << e[i].num << endl;
            }
        }
    }
    return 0;
}