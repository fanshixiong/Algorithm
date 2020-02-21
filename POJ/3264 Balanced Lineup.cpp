/*
倍增
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int maxn = 5e4 + 10;
int maxsum[maxn][20], minsum[maxn][20];
void RMQ(int num){
    for (int j = 1; (1<<j) <= num; j++){
        for (int i = 1; i+(1<<j)-1 <= num; i++){
            if(i+(1<<j)-1<=num){
                maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
                minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}
int n, q;
int main(){
    while(~scanf("%d%d", &n, &q)){
        //cin >> n >> q;
        for (int i = 1; i<=n; i++){
            int x;
            scanf("%d", &x);
            maxsum[i][0] = x;
            minsum[i][0] = x;
        }
        RMQ(n);
        while(q--){
            int x, y;
            scanf("%d%d", &x, &y);
            int z = 0;
            while((1<<(z+1)) <= y-x+1)
                z++;
            int ans = max(maxsum[x][z], maxsum[y - (1 << z) + 1][z]) - min(minsum[x][z], minsum[y - (1 << z) + 1][z]);
            printf("%d\n", ans);
        }
    }
    return 0;
}