#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+7;
vector<int> v[maxn];
priority_queue<int ,vector<int>, greater<int> > q;
int main(){
	ios::sync_with_stdio(0);
    int t;
    cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0; i<=n; i++)
			v[i].clear();
		while(!q.empty()){
			q.pop();
		}
		for(int i=0; i<n; i++){
			int m, p;
			cin >> m >> p;
			v[m].push_back(p);
		}
		ll ans = 0;
		int cnt=0;
		for(int i=n; i>=0; i--){
			int len=v[i].size();
			for(int j=0; j<len; j++)
				q.push(v[i][j]);
			while(q.size() > n-i){
				ans += q.top();
				q.pop();
			}
		}
		cout << ans << endl;
    }
} 
