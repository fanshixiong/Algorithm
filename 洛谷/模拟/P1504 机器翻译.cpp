#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin >> m >> n;
	int vis[100007] = {0};
	int rom[1005];
	int left = 0, right = 0, x;
	int res = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		if(right-left < m && !vis[x]){
			rom[right] = x;
			right++;
			res++;
			vis[x]++;
		}
		else if(right-left >= m && !vis[x]){
			vis[rom[left]]--;
			vis[x]++;
			rom[right] = x;
			res++;
			left++; right++;
		}
	}
	//for (int i = 0; i < 10; i++)
	//	cout << rom[i] << " ";
	//cout << endl;
	cout <<res << endl;
	return 0;
}
