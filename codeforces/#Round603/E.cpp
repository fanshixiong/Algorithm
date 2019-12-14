#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n, max_pre[maxn<<2], min_pre[maxn<<2], sum_pre[maxn<<2];
string s;
void pushup(int id){
    sum_pre[id] = sum_pre[id<<1] + sum_pre[id<<1|1];
    max_pre[id] = max(sum_pre[id<<1]+max_pre[id<<1|1], max_pre[id<<1]);
    min_pre[id] = min(min_pre[id<<1|1]+sum_pre[id<<1], min_pre[id<<1]);

}
void update(int id, int left, int right, int cur, int x){
    if(left == right){
        sum_pre[id] = max_pre[id] = min_pre[id] = x;
        return;
    }
    int mid = (left+right)>>1;
    if(cur <= mid){
        update(id<<1, left, mid, cur, x);
    }
    else{
        update(id<<1|1, mid+1, right, cur, x);
    }
    pushup(id);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int cur = 1;
    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            if(cur > 1)
                cur--;
        }
        else if(s[i] == 'R')
            cur++;
        else if (s[i] == '(')
            update(1, 1, n, cur, 1);
        else if(s[i] == ')')    
            update(1, 1, n, cur, -1);
        else
            update(1, 1, n, cur , 0);
        if(sum_pre[1] != 0 || min_pre[1] < 0)
            cout << -1 << " ";
        else{
            cout << max_pre[1] << " ";
        }
        
        
    }
    return 0;
}