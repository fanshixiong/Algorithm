#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int maze[2][maxn];
int n, q;
int cnt = 0; //没想到  ☞命门个数
bool check(int x, int y){
    if(maze[x][y]){
        maze[x][y] = 0;
        for (int i = -1; i <= 1; i++){
            if(maze[1-x][i+y])
                cnt--;
        }
    }
    else{
        for (int i = -1; i <= 1; i++){
            if(maze[1-x][i+y])
                cnt++;
        }
        maze[x][y] = 1;
    }
    return cnt <= 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    memset(maze, 0, sizeof(maze));
    while(q--){
        int x, y;
        cin >> x >> y;
        x--;
        if(check(x, y)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}