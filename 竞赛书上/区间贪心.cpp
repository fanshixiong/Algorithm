/*����̰�ģ�����n�������䣬�����ܶ��ѡ����Щ����ʹ������֮��û�н��� �������ཻ����ĸ��� 
�����������䰴��˵�Ӵ�С�����У�ÿ��ѡȥ��˵�ֵ�������䣬�������� 
*/
/*
���N���������� ʹÿ�����䶼����һ�����  ��Сȷ���ĵ���
ֻ��ʹLastLeft > I[i].right; 
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
	return x.left != y.left ? x.left > y.left : x.right < y.right;     //�Ȱ���˵�ֵ������򣬽��Ŷ�ÿ��������Ҷ˵㰴��С�������� 
}
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> I[i].left >> I[i].right;
	sort(I, I+n, cmp);
	int res = 1, LastLeft = I[0].left; //��¼��һ����ѡ�е��������˵�
	for (int i = 0; i < n; i++){
		if (LastLeft >= I[i].right){
			res++;
			LastLeft = I[i].left;
		}
	} 
	cout << res << endl;
	return 0;
} 
