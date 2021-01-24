#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int n, ans = 0;
bool check(vector<int> &queens, int row, int col){
    for(int i=0; i<row; i++){
       if(queens[i] == col || abs(queens[i]-col) == abs(i-row))return false;
    }
    return true; 
}
void print(vector<int> queens){
    for (int i = 0; i < n; i++) cout << queens[i] + 1 << " ";
    cout << endl;
}
void dfs(vector<int> &queens, int row){
    if(row == n){
        if(ans < 3) print(queens);
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if(check(queens, row, i)){
            queens[row] = i;
            dfs(queens, row+1);
            queens[row] = -1;
        }
    }
}
int totalNQueens() {
    vector<int> queens(n, -1);
    dfs(queens, 0);
    return ans;
}
int main(){
    cin >> n;
    cout << totalNQueens() << endl;
    return 0;
}