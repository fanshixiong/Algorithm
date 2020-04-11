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
const int N=505,mod=1e9;
const ld eps=1e-12,inf=1e18;
int T;
ll n;
vector<pr>ans;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%lld",&n);
        ans.clear();
        if(n<=30)rep(i,n)ans.pb(mp(i,1));
        else{
            n-=30;int sta=30;
            bool flag=0;
            for(int i=1;i<=30;++i)
                if(n&(1<<(i-1))){
                    if(!flag)rep(j,i)ans.pb(mp(i,j));
                    else rep(j,i)ans.pb(mp(i,i-j+1));
                    flag^=1;
                }else{
                    if(!flag)ans.pb(mp(i,1));
                    else ans.pb(mp(i,i));
                    --sta;
                }
            for(int i=30+1;i<=30+sta;++i)
                if(!flag)ans.pb(mp(i,1));
                else ans.pb(mp(i,i));
        }
        printf("Case #%d:\n",Cas);
        for(pr p:ans)printf("%d %d\n",p.st,p.nd);
    }
    return 0;
}