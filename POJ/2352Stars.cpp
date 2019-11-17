#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 32010;
struct node{
    int x,y;
}star[1500001];
int n,d[3200001],ji[1500001],m;
bool cmp(node &a,node &b){
    if(a.x<b.x)
      return true;
    else if(a.x>b.x)
      return false;
    else if(a.y<b.y)
      return true;
    return false;
}
int lowbit(int x){
    return x&(-x);
}
void update(int x,int delta){
    for(;x<N;x+=lowbit(x))
      d[x]+=delta;
}
int getsum(int x){
    int res=0;
    for(;x>0;x-=lowbit(x))
      res+=d[x];
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&star[i].x,&star[i].y);
		star[i].x++;
		ji[getsum(star[i].x)]++;
		update(star[i].x,1);
    }
    
    for(int i=0;i<n;i++)
    	printf("%d\n",ji[i]);
    return 0;
}
