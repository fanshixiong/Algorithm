//A-二维偏序+树状数组
 /*
 二维偏序，就是一个思想，可以用树状数组实现。
 */
 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
 
int w[maxn],sum[maxn];
int n;
 
struct node{
     int x,y;
}a[maxn];
 
bool cmp(node a,node b){
	return a.x<b.x;
}
int lowbit(int x){
    return x&(-x);
}
 
int query(int n){
	int ans=0;
 	for(int i=n;i>0;i-=lowbit(i)){
        ans+=sum[i];
 	}
    return ans;
}
 
void add(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        sum[i]++;
    }
}
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        w[i]=a[i].y;
    }
    sort(w+1,w+1+n);  //按y排序 
    int d=unique(w+1,w+1+n)-(w+1); //去重 
    for(int i=1;i<=n;i++){
        a[i].y=lower_bound(w+1,w+1+d,a[i].y)-w; //取大于等于y的元素的下标 
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=n;i>0;i--){
        int cnt=query(a[i].y);
        if(n-i-cnt!=0) ans++;//n-i是找比x当前i大的，然后再减去cnt是比当前i小的y的，最后就是都比当前的大的
        add(a[i].y);
    }
    printf("%d\n",ans);
 }
