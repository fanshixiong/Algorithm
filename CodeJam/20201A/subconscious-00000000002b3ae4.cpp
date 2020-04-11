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
const int N=105,mod=1e9;
const ld eps=1e-12,inf=1e18;
int T,n,len[N],u[N],d[N];
char s[N][N],ans[3][N*N];

int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        rep(i,n){
            scanf("%s",s[i]+1);
            len[i]=strlen(s[i]+1);
        }
        rep(i,n){
            u[i]=1;while(s[i][u[i]]!='*')++u[i];
            --u[i];
            d[i]=1;while(s[i][len[i]-d[i]+1]!='*')++d[i];
            --d[i];
        }
        bool flag=0;
        int mx=1;
        rep(i,n)if(u[mx]<u[i])mx=i;
        rep(i,n)rep(j,u[i])if(s[i][j]!=s[mx][j])flag=1;
        rep(i,u[mx])ans[0][i]=s[mx][i];
        ans[0][u[mx]+1]='\0';
        //printf("%d\n",flag);
        mx=1;
        rep(i,n)if(d[mx]<d[i])mx=i;
        rep(i,n)rep(j,d[i])if(s[i][len[i]-j+1]!=s[mx][len[mx]-j+1])flag=1;
        rep(i,d[mx])ans[2][d[mx]-i+1]=s[mx][len[mx]-i+1];
        ans[2][d[mx]+1]='\0';
        int top=0;
        rep(i,n)
            for(int j=u[i]+1,k;j<=len[i]-d[i];j=k){
                k=j+1;while(s[i][k]!='*'&&k<=len[i]-d[i])++k;
                for(int p=j+1;p<=k-1;++p)ans[1][++top]=s[i][p];
            }
        ans[1][top+1]='\0';
        if(flag)printf("Case #%d: *\n",Cas);
        else printf("Case #%d: %s%s%s\n",Cas,ans[0]+1,ans[1]+1,ans[2]+1);
    }
    return 0;
}