/* ���ϸ�ð��
������ �ҳ���ð��������������ߵ����ϸ���    ���ұ������ߵ����ϸ����� ������ж������ð�������Ƿ��ڱ߽�λ�ü��� 
*/ 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
int main(){
	freopen("in.txt", "r", stdin); 
	int n; cin >> n;
	vector<pair<int, int> > nums;
	int x; cin >> x;
	int bl = x < 0 ? -1 : 1;
	nums.push_back(pair<int, int> (abs(x), bl)); 
	for (int i = 1; i < n; i++){
		int a; cin >> a;
		int b = a < 0 ? -1 : 1;
		nums.push_back(pair<int, int> (abs(a), b)); 
	}
	sort(nums.begin(), nums.end());
	int res = 1;
	if (bl > 0){
		int pos = 0;
		for (int i = n-1; i >= 0; i--){
			if (nums[i].first == abs(x) && nums[i].second == bl)
				pos = i;
			if (nums[i].second < 0 && pos < i)
				res++;
			else if (nums[i].second > 0 && pos > i)
				res++;
		}
	}
	else{
		int pos = n;
		for (int i = 0; i < n; i++){
			if (nums[i].first == abs(x) && nums[i].second == bl)
				pos = i;
			if (nums[i].second > 0 && pos > i)
				res++;
			else if (nums[i].second < 0 && pos < i)
				res++;
		}
	}
	cout << res << endl;
	return 0;
}

