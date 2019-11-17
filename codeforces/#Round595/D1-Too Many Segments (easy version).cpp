#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
int main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int, int > > segs(n);
	vector<int> cnt(maxn);
	for(int i=0; i<n; i++){
		cin >> segs[i].first >> segs[i].second;
		++cnt[segs[i].first];
		--cnt[segs[i].second+1];
	}
	for(int i=0; i<maxn-1; i++)
		cnt[i+1] += cnt[i];
	vector<int> ans(n);
	for(int i=0; i<maxn; i++){
		while(cnt[i] > k){
			int pos = -1;
			for(int p=0; p<n; p++){
				if(!ans[p] && (segs[p].first<=i && segs[p].second>=i) && (pos == -1 || segs[p].second > segs[pos].second))
					pos = p;
			}
			//cout << i << "  " << pos << endl;
			if(pos == -1)
				break;
			for(int j=segs[pos].first; j<=segs[pos].second; j++)
				--cnt[j];
			ans[pos]=1;
		}
	}
	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for(int i=0; i<n; i++){
		if(ans[i])
			cout << i+1 << " ";
	}
	cout << endl;
	return 0;
}
