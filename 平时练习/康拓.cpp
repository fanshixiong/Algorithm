/*康托展开和逆康托展开 
康托展开：在全排列问题中，随机给出一个排列，问他是全排列中按字典序排列的第几个排列： 
	分析：  公式：x = a[0]*(n-1)! + a[1]*(n-2)! + ... ... + a[n-1]*1! + a[n]*0!;  其中 ：a[i]是指未出现的元素在排列中的次序
	例子：  1234的全排列中，3214是第几个排列？  x = 2*3! + 1*2! + 0*1! + 0*0! = 14;  因为3在3214这个排列比它小的数有2个（有0），去掉3后2排第1。。。。
逆康托展开：在全排列问题中，求排在随机给出一个自然数的排列；x
	分析：   （x-1）/ (n-1)!  商y与余数z 说明排在第一位前面有y个元素比他小，。。。。
	例子：  在1234中 第20个排列是什么：
	        19 / 3！ = 3...2 说明排在第一位的元素前面有3个元素比他小 说明第一位是4
			2  / 2！ = 1...0 说明排在第二位的元素前面有1个元素比他小 说明第二位是2
			0  / 1！ = 0...0 说明排在第三位的元素前面有0个元素比他小 说明第三位是1
			...第四位是3 
作用： 全排列问题，第二是求解八数码问题 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
void cantor(){
	string target; cin >>target;
	vector<int> nums;
	int n = target.size();
	for (int i = 0 ; i < n; i++){
		nums.push_back(target[i]-'0');
	}
	int res = 0;
	for (int i = 0; i < n-1; i++){
		int small = 0;
		for (int j = i+1; j < n; j++)
			if (nums[i] > nums[j]) small++;
		res += small * FAC[n-i-1];
	}
	cout << res << endl;
} 
int decantor(){
	int n, x; cin >> n;
	vector<int> nums(n);
	vector<int> res;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	cin >> x;
	int m = x-1, y = x-1;
	for (int i = 0; i < n; i++){
		m = y / FAC[n-i-1];
		y = y % FAC[n-i-1];
		sort(nums.begin(), nums.end());
		res.push_back(nums[m]);
		nums.erase(nums.begin() + m); 
	}
	for (int i = 0; i < n; i++)
		cout << res[i];
	cout << endl;
}
int main(){
	cantor();
	decantor();
	return 0;
} 
