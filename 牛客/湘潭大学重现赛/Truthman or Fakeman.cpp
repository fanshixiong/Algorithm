#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int parent[300005];
int cnt[300006];
int vis[300006];
int Find(int x){
    if(x==parent[x])
        return x;
    return parent[x]=Find(parent[x]);
}
void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y)
        return;
    parent[x]=y;
    cnt[x]+=cnt[y];  //�������ж��ٸ�Ԫ��
}
void Solve(){
    for(int i=1; i<=n; i++){
        int x=Find(i), y=Find(i+n);
        if(x==y){
            cout << -1 << endl;
            return;
        }
        if(!vis[x]){  //���л�δ����ǹ��ļ���
            if(cnt[x]>cnt[y]){
                vis[x]=1;    //����x��Ԫ�ض࣬������xԪ��ȫ��Ϊ1
                vis[y]=-1;
            }
            else{
                vis[x]=-1;
                vis[y]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(vis[Find(i)]==1)
            cout << 1;
        else    
            cout << 0;
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1; i<=2*n; i++){
            parent[i]=i;
            if(i>n)   //���������һ������Ϊ1
                cnt[i]=0;
            else
                cnt[i]=1;
        }
        for(int i=0; i<m; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if(z){//��Ϊ����߶�Ϊ��
                Union(x, y);  
                Union(x+n, y+n);
            }
            else{//һΪ��һΪ��
                Union(x+n, y);
                Union(x, y+n);
            }
        }
        Solve();
    }
    return 0;
}
