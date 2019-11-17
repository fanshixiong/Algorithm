#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
class Tree{
	vector<int> bit1;
	vector<int> bit2;
	int n;
	vector<int> nums;
public:
	Tree(){
		cin >> n;
		bit1.resize(1000005);
		bit2.resize(1000005);
		nums.resize(n+1);
		for(int i=1; i<=n; i++){
			cin >> nums[i];
			nums[i]++;
		}
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add1(int x){
		while(x<=1000005){                     //注意：不是n 
			bit1[x]++;
			x+=lowbit(x);
		}
	}
	int sum1(int x){
		int res=0;
		while(x){
			res+=bit1[x];
			x-=lowbit(x);
		}
		//cout << res <<endl;	
		return res;
	}
	void add2(int x){
		while(x){
			bit2[x]++;
			x-=lowbit(x);
		}
	}
	int sum2(int x){
		int res=0;
		while(x<=1000005){                    //注意： 不是n 
			res+=bit2[x];
			x+=lowbit(x);
		}
		return res;
	}
	int resolve(){
		vector<int> res(n+1);
		for(int i=1; i<=n; i++){
			add1(nums[i]);
			res[i] = i-sum1(nums[i]);
		//	cout << res[i] << " ";
		}
		//cout << endl;
		long long ans=0, ans1=0;
		for(int i=n; i>0; i--){
			add2(nums[i]);
			res[i]+=(n-i+1)-sum2(nums[i]);
		//	cout << res[i] << " ";
			//ans1+=i-sum2(nums[i]);
		}
		//cout<< endl;
		vector<long long int> dist(1000005);
		for(int i=1; i<n+1; i++){
			dist[i]=dist[i-1]+i;
		}
		for(int i=1; i<=n; i++)
			ans += dist[res[i]];
		cout << ans << endl;
	}
};
int main(){
	Tree test;
	test.resolve();
	return 0;
} 
