//LeetCode123  ��Ʊ�������⣺���⣺��һ���������ÿ����Ʊ�ļ�ֵ���������һ�����룬�����ļ�������������ǰ���������Ʊ�������Ե���������������k�ε�������档

//���������kΪ2����ô���кܶ���˼·��
//1.	���Խ����ν���ת��Ϊһ�ν��ף������жϵ�i��Ľ��������ʱ�򣬼������i�����ʱ��һ�ν��׵���������Լ��ӵ�i�쿪ʼ��������������档��ôͨ���ж�ÿһ������ν��׵��������Ϳ����������档
//���߿����뵽������һ��O(n2)���㷨����ʵ��Ȼ������ͨ�����α�����һ�δ�ǰ�����ҵ�����i��Ϊֹ����һ�ε�������档һ�δӺ���ǰ���ҵ���i��֮���һ�ν��׵�������档������ҵ���������ε����档���������ο����룺


//2. ��̬�滮����ȫ�����ź;ֲ����ţ�
//	�����������������ȥ����������չ��k�˽��ף�����ķ����Ϳ϶������˵ġ�����ά��������̬�滮����
 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n);
	    vector<int> right(n);
	    int minl = 0x3f3f, resl = 0;
	    for (int i = 0; i < n; i++){
		    if (minl > prices[i])
			    minl = prices[i];
		    int dis  = prices[i] - minl;
		    if (dis  > resl)
			    resl = dis;
    		left[i] = resl;
	    }
	    int maxr = 0, resr = 0 , res = 0, dis;
	    for (int i = n-1; i>=0; i--){
		    if (maxr < prices[i])
			    maxr = prices[i];
    		int dis = maxr - prices[i];
	    	if (dis > resr)
		    	resr = dis;
    		right[i] = resr;
            dis = left[i] +right[i];
            if (res < dis)
                res = dis;
        }
        return res;
    }
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >>n;
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); i++)
		cin >> nums[i];

	cout << maxProfit(nums) <<endl;
	return 0; 
}
