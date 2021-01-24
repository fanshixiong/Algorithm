#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int n, ans = 0;
int queens[maxn];
bool check(int row, int col){
    for(int i=0; i<row; i++){
       if(queens[i] == col || abs(queens[i]-col) == abs(i-row))return false;
    }
    return true; 
}
void print(){
    for (int i = 0; i < n; i++) cout << queens[i] + 1 << " ";
    cout << endl;
}
void dfs(int row){
    if(row == n){
        if(ans < 3) print();
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if(check(row, i)){
            queens[row] = i;
            dfs(row+1);
            queens[row] = -1;
        }
    }
}
int totalNQueens() {
    dfs( 0);
    return ans;
}
int main(){
    cin >> n;
    cout << totalNQueens() << endl;
    return 0;
}