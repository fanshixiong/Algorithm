/*小蓝赛：在m个数组中每一组取一个相加，找出前n个元素
优先队列 
*/
#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 2000+5;
int data[maxn][maxn];
struct node{
	int x, y, num;
	bool tag;
	node(int i, int j, int n, bool f):x(i), y(j), num(n), tag(f){
	}
	bool operator < (const node &a)const{
		return num > a.num;
	}
};
void returnline(int x, int y, int n){
	priority_queue<node> q;
	q.push(node(0, 0, data[x][0] + data[y][0], false));
	vector<int> res;
	for (int i = 0; i < n; i++){
		if(!q.empty()){
			node tmp = q.top();
			q.pop();
			res.push_back(tmp.num);
			if (!tmp.tag && tmp.x + 1 < n)
				q.push(node(tmp.x+1, tmp.y, data[x][tmp.x+1]+data[y][tmp.y], false));
			if (tmp.y +	1 < n)
				q.push(node(tmp.x, tmp.y+1, data[x][tmp.x] + data[y][tmp.y+1], true));
		}
	}
	for (int i = 0; i < n; i++)
		data[y][i] = res[i];
	
}
int main(){
	int t; cin >> t;
	while (t--){
		int m,n; cin >> m >> n;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> data[i][j];
			}
			sort(data[i], data[i]+n);
		}
		returnline(0, 1, n);
		for (int i = 2; i < m; i++){
			returnline(i-1, i, n);
		}
		for (int i = 0; i < n; i++)
			cout << data[m-1][i] << " ";
		cout << endl;
	}
	return 0;
}

