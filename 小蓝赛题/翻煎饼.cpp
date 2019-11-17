/*第五周：摊煎饼  通过翻转栈中的元素序列来使得元素有序 
分析： 每次找最大的转到上面，再转到最底层，类似于堆排序的调整过程 
*/
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
void Swap(vector<int> &nums, int x, int y){
	while (x <= y){
		int temp = nums[x];
		nums[x] = nums[y];
		nums[y] = temp;
		x++; y--;
	}
}
int main(){
	freopen("in.txt", "r", stdin);
	while (cin.get() != '\n' ){
		cin.unget();
		int a;
		vector<int> nums, res, b;
		while (cin.get()  != '\n'){
			cin.unget();		
			cin >> a;
			nums.push_back(a); 
			b.push_back(a);
		}
		for (int i = 0 ; i < nums.size() ; i++)
			cout << nums[i] << " " ;
		cout << endl;
		sort(b.begin(), b.end());
		int x = b.size();
		while (x){
			int i = 0;
			for(; i < b.size() && nums[i] < b[x-1]; i++);
			if (nums[i] == b[i]){
				x--;
				continue;
			}
			if (i>0)
				res.push_back(b.size()-i);
			Swap(nums,0, i);
			if (nums[x-1] != b[x-1]){
				res.push_back(b.size()-x+1);
				Swap(nums, 0, x-1);
			}
			x--;
		}
		/*
		for (int i = 0 ; i < nums.size() ; i++)
			cout << nums[i] << " " ;
		cout << endl;
		*/
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << "0" << endl;
	}
	return 0;
}
