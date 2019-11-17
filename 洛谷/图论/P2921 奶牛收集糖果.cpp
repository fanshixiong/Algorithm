
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
int N;
vector<int> parents(100005);
vector<int> fa(100005);
vector<int> ans(100005);
int Find(int x){
	if(x == parents[x])
		return x;
	return parents[x]=Find(parents[x]);
}
void Union(int x, int y){
	int m = Find(x);
	int n = Find(y);
	if(m == n){
		int res = 1;
		for (int j = y; j!=x; j=fa[j]){
			res++;
		}
		for (int j = y; j!=x; j=fa[j]){
			ans[j]=res;
		}
		ans[x]=res;
	}
	else{
		parents[m]=n;
		fa[x]=y;
	}
}
int main(){
	cin >> N;
	for (int i = 1; i <= N; i++)
		parents[i]=i;
	for (int i = 1; i <= N; i++){
		int y;
		cin >> y;
		Union(i, y);
	}
	for (int i = 1; i <= N; i++){
		if(!ans[i]){
			int res = 1, j;
			for (j = fa[i]; !ans[j]; j=fa[j])
				res++;
			ans[i] = res+ans[j];
		}
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N;cin >> N;
	vector<int> horse(N+1);
	for (int i = 1; i<=N; i++)
		cin >> horse[i];
	vector<int> color(N+1), enter_time(N+1), time(N+1), hook_size(N+1);
	//分别代表  颜色， 入环时间戳 ， 时间戳， 环的大小
	int cnt; //时间戳 
	for(int cow = 1; cow <= N; cow++){
		for (int i = cow, cnt=0; ; i=horse[i], ++cnt){
			if(!color[i]){
				color[i]=cow;
				time[i]=cnt;
			}
			else if(color[i]==cow){
				hook_size[cow]=cnt-time[i];
				enter_time[cow]=time[i];
				cout << cnt << endl;
				break;
			}
			else{
				enter_time[cow]=cnt+max(0, enter_time[color[i]]-time[i]);
				hook_size[cow]=hook_size[color[i]];
				cout << hook_size[cow]+enter_time[cow] << endl;
				break;
			}
		}
	} 
}
*/
