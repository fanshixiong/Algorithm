/*区间贪心：给出n个开区间，尽可能多的选择这些区间使得两两之间没有交集 ，即求不相交区间的个数 
分析：将区间按左端点从大到小的排列：每次选去左端点值最大的区间，更新区间 
*/
/*
求解N个闭区间中 使每个区间都包含一个点的  最小确定的点数
只需使LastLeft > I[i].right; 
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1001;
struct Interval{
	int left, right;
}I[maxn]; 
bool cmp(Interval x, Interval y){
	return x.left != y.left ? x.left > y.left : x.right < y.right;     //先按左端点值大的排序，接着对每个区间的右端点按从小到大排序 
}
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> I[i].left >> I[i].right;
	sort(I, I+n, cmp);
	int res = 1, LastLeft = I[0].left; //记录上一个被选中的区间的左端点
	for (int i = 0; i < n; i++){
		if (LastLeft >= I[i].right){
			res++;
			LastLeft = I[i].left;
		}
	} 
	cout << res << endl;
	return 0;
} 
