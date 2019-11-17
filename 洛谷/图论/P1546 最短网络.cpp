#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int beg, end, value;
	node(){
		beg=end=value=0;
	}
};
bool cmp(node &a, node &b){
	return a.value < b.value;
}
class Farm{
	int N;
	int ans;
	vector<node> T;
	vector<int> parent;
public:
	Farm(){
		cin >> N; ans=0;
		parent.resize(N+1);
		for (int i = 1; i<=N; i++){
			parent[i]=i;
			for (int j=1; j<=N; j++){
				int x; cin >> x;
				if(j>i){
					node tp;
					tp.value=x;
					tp.beg=i; tp.end=j;
					T.push_back(tp); 
				}
			}
		}
		sort(T.begin(), T.end(), cmp);
		//for (int i=0; i<T.size(); i++){
		//	cout << T[i].beg << " " << T[i].end << " "<< T[i].value << endl;
		//}
	}
	int Find(int x){
		if (parent[x] == x)
			return x;
		return parent[x]=Find(parent[x]);
	}
	void Kruskal(){
		int k=0;
		for (int i = 0; i < T.size(); i++){
			if(Find(T[i].beg)!=Find(T[i].end)){
				ans+=T[i].value;
				parent[Find(T[i].beg)]=T[i].end;             //µÚÒ»´Î´íÎó 
				k++;
				if(k==N)break;
			}
		}
		cout << ans << endl;
	}
};
int main(){
	Farm test;
	test.Kruskal();
	return 0;
} 
