#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
int main()
{
    ios_base::sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    int flg = 0;
    if(c == 1 && r == 1){
        cout << 0 << endl;
        return 0;
    }
    if(r > c){
        swap(r, c);
        flg = 1;
    }
    for (int i = 0; i < c; i++){
        a[0][i] = i + 2;
    }
    for (int i = 1; i < r; i++){
        for (int j = 0; j < c; j++){
            a[i][j] = (c + i + 1) * a[0][j];
        }
    }
    if(flg){
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                b[j][i] = a[i][j];
            }
        }
        swap(r, c);
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(flg)
                cout << b[i][j] << " ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}