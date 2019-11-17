#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn = 3e5+10;
const int N=26;
char s[maxn], ss[maxn];
ll ans = 0;
int vis[26];
struct Palindromic_Tree{
	int next[maxn][26]; //next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成。 
	int fail[maxn];  //fail指针，失配后跳转到 fail指针所指向的节点 
	//回文树里面的一个节点就代表一个回文串 
	int cnt[maxn];   //表示第i个节点代表的回文串出现的次数 
	int num[maxn];  //表示以节点i表示的最长回文串的最右端为回文串结尾的回文串的个数 
	int len[maxn];  //表示第i个节点代表的回文串长度 
	 
	int S[maxn];  //存放添加的字符 
	int last;  //指向上一个字符所在的节点，方便下一次add 
	int n;    //字符数组指针 
	int p;    //节点指针 
	int newnode(int l){  //在树中建立新节点 
		for(int i=0; i<N; i++){
			next[p][i]=0;
		}
		cnt[p]=0;
		num[p]=0;
		len[p]=l;
		return p++;
	}
	void init(){  //初始化
		p=0;
		newnode(0); //建立一颗保存长度为偶数的回文树 
		newnode(-1); //长度为奇数的回文树 
		last=0;
		n=0;
		S[n]=-1; //开头放一个字符集中没有的字符，减少特判。 
		fail[0]=1;
	}
	int get_fail(int x){ //和kmp一样，失配后找一个尽量长的 
		while(S[n-len[x]-1] != S[n]){
			x = fail[x];
		}
		return x;
	}
	void add(int c, int pos){
		//printf("%d", p); // 输出节点编号，第一个you回文串的编号是从2开始的。
		c -= 'a';
		S[++n] = c;
		int cur = get_fail(last); //通过上一个回文串找到这个回文串的匹配位置 
		//pritnf("%d ", cur); //输出节点编号p代表的回文串的字符长度 
		if(!next[cur][c]){  //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串 
			int now = newnode(len[cur]+2);  //新建节点 
			fail[now] = next[get_fail(fail[cur])][c]; // 和ac自动机一样，以便失配后跳转 
			
			next[cur][c] = now;
			num[now] = num[fail[now]]+1;
		} 
		last = next[cur][c];
		cnt[last]++;
		//putchar(10); --输出回车换行 
	} 
	void count(){
		for(int i=p-1; i>=0; i--){
			cnt[fail[i]] += cnt[i];
			//父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
		}
	} 
	void dfs(int x, int y){
		for(int i=0; i<26; i++){
			if(next[x][i]){
				int z; //回文串里不同数字的个数 
				if(vis[i]){ //标记回文串出现字母的种类 
					z=y;
					ans += z*cnt[next[x][i]];
					dfs(next[x][i], z);
				}
				else{
					z = y+1;
					vis[i]++;
					ans += z*cnt[next[x][i]];
					dfs(next[x][i], z);
					vis[i]--; // 回溯 
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
