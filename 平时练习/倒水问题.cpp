#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
 
using namespace std;
const int maxn = 200 + 5;
struct node{
    int val[3], d;
    bool operator < (const node &p) const {
        return d > p.d;
    }
};
int vis[maxn][maxn], ans[maxn];
 
void update(const node &u){//及时更新倒水量
    for(int i = 0; i < 3; ++i){
        int v = u.val[i];
        if(ans[v] < 0 || ans[v] > u.d)  ans[v] = u.d;
    }
}
 
void bfs(int a, int b, int c, int d){
    int cap[] = {a, b, c};//容量大小
    priority_queue<node> q;
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    node u;
    u.val[0] = 0;  u.val[1] = 0;//开始的状态
    u.val[2] = c;  u.d = 0;
    q.push(u);
 
    vis[0][0] = 1;
    while(!q.empty()){
        u = q.top();  q.pop();
        update(u);
        if(ans[d] >= 0)  break;//找到d了 及时退出
 
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j){
                if(i == j || !u.val[i] || u.val[j] == cap[j])  continue;//i 是空的，或者 j 是已经满了
 
                node v;   
				memcpy(&v, &u, sizeof(u));
                int t = min(cap[j], v.val[i]+v.val[j]) - v.val[j];//找倒水量，要么倒满，要么倒空
                v.val[i] -= t;
                v.val[j] += t;
                v.d += t;
                if(vis[v.val[0]][v.val[1]])  continue;
                vis[v.val[0]][v.val[1]] = 1;//标记的不是 vis[v.val[j]][v.val[j]]
                q.push(v);
            }
 
    }
 
    while(d >= 0){
        if(ans[d] >= 0){ printf("%d %d\n", ans[d], d);  return ;  }
        --d;//找最近的
    }
}
 
int main(){
//    freopen("in.txt", "r", stdin);
    int T, a, b, c, d;  cin >> T;
    while(T--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bfs(a, b, c, d);
    }
    return 0;
}
