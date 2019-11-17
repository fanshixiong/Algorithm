#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn = 3e5+10;
const int N=26;
char s[maxn], ss[maxn];
ll ans = 0;
int vis[26];
struct Palindromic_Tree{
	int next[maxn][26]; //nextָ�룬nextָ����ֵ������ƣ�ָ��Ĵ�Ϊ��ǰ�����˼���ͬһ���ַ����ɡ� 
	int fail[maxn];  //failָ�룬ʧ�����ת�� failָ����ָ��Ľڵ� 
	//�����������һ���ڵ�ʹ���һ�����Ĵ� 
	int cnt[maxn];   //��ʾ��i���ڵ����Ļ��Ĵ����ֵĴ��� 
	int num[maxn];  //��ʾ�Խڵ�i��ʾ������Ĵ������Ҷ�Ϊ���Ĵ���β�Ļ��Ĵ��ĸ��� 
	int len[maxn];  //��ʾ��i���ڵ����Ļ��Ĵ����� 
	 
	int S[maxn];  //�����ӵ��ַ� 
	int last;  //ָ����һ���ַ����ڵĽڵ㣬������һ��add 
	int n;    //�ַ�����ָ�� 
	int p;    //�ڵ�ָ�� 
	int newnode(int l){  //�����н����½ڵ� 
		for(int i=0; i<N; i++){
			next[p][i]=0;
		}
		cnt[p]=0;
		num[p]=0;
		len[p]=l;
		return p++;
	}
	void init(){  //��ʼ��
		p=0;
		newnode(0); //����һ�ű��泤��Ϊż���Ļ����� 
		newnode(-1); //����Ϊ�����Ļ����� 
		last=0;
		n=0;
		S[n]=-1; //��ͷ��һ���ַ�����û�е��ַ����������С� 
		fail[0]=1;
	}
	int get_fail(int x){ //��kmpһ����ʧ�����һ���������� 
		while(S[n-len[x]-1] != S[n]){
			x = fail[x];
		}
		return x;
	}
	void add(int c, int pos){
		//printf("%d", p); // ����ڵ��ţ���һ��you���Ĵ��ı���Ǵ�2��ʼ�ġ�
		c -= 'a';
		S[++n] = c;
		int cur = get_fail(last); //ͨ����һ�����Ĵ��ҵ�������Ĵ���ƥ��λ�� 
		//pritnf("%d ", cur); //����ڵ���p����Ļ��Ĵ����ַ����� 
		if(!next[cur][c]){  //���������Ĵ�û�г��ֹ���˵��������һ���µı��ʲ�ͬ�Ļ��Ĵ� 
			int now = newnode(len[cur]+2);  //�½��ڵ� 
			fail[now] = next[get_fail(fail[cur])][c]; // ��ac�Զ���һ�����Ա�ʧ�����ת 
			
			next[cur][c] = now;
			num[now] = num[fail[now]]+1;
		} 
		last = next[cur][c];
		cnt[last]++;
		//putchar(10); --����س����� 
	} 
	void count(){
		for(int i=p-1; i>=0; i--){
			cnt[fail[i]] += cnt[i];
			//�����ۼӶ��ӵ�cnt����Ϊ���fail[v]=u����uһ����v���ӻ��Ĵ���
		}
	} 
	void dfs(int x, int y){
		for(int i=0; i<26; i++){
			if(next[x][i]){
				int z; //���Ĵ��ﲻͬ���ֵĸ��� 
				if(vis[i]){ //��ǻ��Ĵ�������ĸ������ 
					z=y;
					ans += z*cnt[next[x][i]];
					dfs(next[x][i], z);
				}
				else{
					z = y+1;
					vis[i]++;
					ans += z*cnt[next[x][i]];
					dfs(next[x][i], z);
					vis[i]--; // ���� 
				}
			}
		}
	}
}pat;
int main(){
	ans = 0;
	scanf("%s", &s);
	int n=strlen(s);
	pat.init();
	for(int i=0; i<n; i++){
		pat.add(s[i], i);
	}
	pat.count();
	pat.dfs(0, 0);
	memset(vis, 0, sizeof(vis));
	pat.dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
