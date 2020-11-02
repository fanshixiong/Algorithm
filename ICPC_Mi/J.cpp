#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    int a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int A[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i + a < n; i++){
        for (int j = 0; j + b < m; j++){
            if(A[i][j] != 0){
                int t = A[i][j];
                for (int p = 0; p < a; p++){
                    for (int q = 0; q < b; q++){
                        int x = p + i, y = q + j;
                        A[x][y] -= t;
                        if(A[x][y] < 0){
                            printf("QAQ\n");
                            return;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if(A[i][j] != 0){
                printf("QAQ\n");
                return;
            }
        }                            
    
    printf("^_^\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}