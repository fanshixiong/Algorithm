#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
const int N=1e5+5,mod=1e9;
const ld eps=1e-12,inf=1e18;
// (1,0) (0,1) (-1,0) (0,-1)
int T,r,c;
ll ans,tot;
int num[N],lk[4][N],tmp[4];
bool in[N];
vector<int>del,nxt;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d%d",&r,&c);
        ans=tot=0;
        rep(i,r)rep(j,c){
            int now=(i-1)*c+j;
            scanf("%d",num+now);
            tot+=num[now];
            in[now]=1;
            if(i==r)lk[0][now]=0;else lk[0][now]=(i)*c+j;
            if(j==c)lk[1][now]=0;else lk[1][now]=(i-1)*c+(j+1);
            if(i==1)lk[2][now]=0;else lk[2][now]=(i-2)*c+j;
            if(j==1)lk[3][now]=0;else lk[3][now]=(i-1)*c+(j-1);
        }
        del.clear();
        nxt.clear();
        rep(i,r*c)nxt.pb(i);
        for(;;){
            ans+=tot;
            for(int now:nxt){
                int cnt=0,sum=0;
                for(int i=0;i<4;++i)
                    if(lk[i][now]!=0)++cnt,sum+=num[lk[i][now]];
                if(cnt*num[now]<sum)del.pb(now),in[now]=0;
            }
            if(del.size()==0)break;
            nxt.clear();
            for(int now:del){
                //printf("%d ",now);
                tot-=num[now];
                for(int i=0;i<4;++i)
                    tmp[i]=lk[i][now];
                for(int i=0;i<4;++i)
                    if(tmp[i]!=0&&in[tmp[i]])nxt.pb(tmp[i]);
                for(int i=0;i<4;++i)
                    if(tmp[i]!=0)lk[i^2][tmp[i]]=tmp[i^2];
            }
            //puts("");
            del.clear();
            sort(nxt.begin(),nxt.end());
            nxt.resize(unique(nxt.begin(),nxt.end())-nxt.begin());
        }
        printf("Case #%d: %lld\n",Cas,ans);
    }
    return 0;
}