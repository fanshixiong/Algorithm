/* É¸·¨ÇóËØÊý 
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int maxn = 10000000;
int Find_Prime(vector<int> &prime, vector<bool> &vis){
	int pnum = 0;
	for (int i = 2; i < maxn; i++){
		if (!vis[i]){
			prime[pnum++] = i;
			for (int j = i+i; j < maxn; j+=i)
				vis[j] = 1;
		}
	}
	return pnum;
}

int main(){
	int m, n;
	cin >> m >> n;
	vector<int> prime(maxn);
	vector<bool> vis(maxn);
	int k = Find_Prime(prime, vis);
	for (int i = m; i < k; i++)
		cout << prime[i] <<" ";
	return 0;
} 
