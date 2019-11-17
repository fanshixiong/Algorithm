//A-��άƫ��+��״����
 /*
 ��άƫ�򣬾���һ��˼�룬��������״����ʵ�֡�
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
    sort(w+1,w+1+n);  //��y���� 
    int d=unique(w+1,w+1+n)-(w+1); //ȥ�� 
    for(int i=1;i<=n;i++){
        a[i].y=lower_bound(w+1,w+1+d,a[i].y)-w; //ȡ���ڵ���y��Ԫ�ص��±� 
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=n;i>0;i--){
        int cnt=query(a[i].y);
        if(n-i-cnt!=0) ans++;//n-i���ұ�x��ǰi��ģ�Ȼ���ټ�ȥcnt�Ǳȵ�ǰiС��y�ģ������Ƕ��ȵ�ǰ�Ĵ��
        add(a[i].y);
    }
    printf("%d\n",ans);
 }
