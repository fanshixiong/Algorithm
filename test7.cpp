#include<iostream>
#include<cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int converse(int n, int k){
	deque<int> q;
	int chus;
	int yus;
	while(n){
		chus = n / k;
		yus = n % k;
		q.push_front(yus);
		n = chus;
	}
	int res = 0;
	while (!q.empty()){
		
		res = res*10 + q.front();
		q.pop_front();
	}
	return res;
} 
int main(){
	int n; cin >> n;
	int res = 0;
	string before;
	while (n--){
		string now;
		cin >> now;
		if (now == 'CLEAR')  res = 0;
		else if (now == 'EQUAL')  cout << res <<endl;
		else if (now == 'CHANGE') {
			int k; 
			cin >> k; 
			res = converse(res, k);
		}
		else if (now == 'NUM'){
			int x; cin >> x;
			if (before == 'ADD')
				res += x;
			else if (before == 'SUB')
				res -= x;
			else if (before == 'MUL')
				res *= x;
			else if (before == 'DIV')
				res /= x;
			else if (before ==  'MOD')
				res = res % x;
		}
		before = now;
	}
	return 0;
}
