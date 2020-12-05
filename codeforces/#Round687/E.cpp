#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int nmax=1010;
int father[nmax];
int isRoot[nmax];
 
int findFather(int u){
    if(u==father[u]) return u;
    else{
        int f=findFather(father[u]);
        father[u]=f;
        return f;
    }
} 
 
void Union(int u,int v){
    int fu=findFather(u);
    int fv=findFather(v);
    if(fu!=fv){
        father[fu]=fv;
    } 
}
 
void init(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
        isRoot[i]=0;
    }
}
 
int main(int argc, char** argv) {
    int n,m;//点数，边数
    while(cin>>n>>m){
        if(n==0){
            break;
        }
        memset(father,0,sizeof(father));
        memset(isRoot,0,sizeof(isRoot));
        init(n);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            Union(u,v);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(father[i]==i){
                ans++;
            }
        }
        if(ans==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    } 
    return 0;
}