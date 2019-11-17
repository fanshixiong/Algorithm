#include <iostream>
#include <vector>
using namespace std;
                                                            //��������������������ֵ  
struct Node{
	int data;          //Ԫ�� 
	int x;            //�±� 
}humque[10000];

void getMin (vector<int> &min, vector<int> &nums, int m){   //min����������Сֵ ��mΪ���� 
	int head = 0, tail = 0;                               //head ����ͷ tail����β 
	humque[tail].data = nums[0]; 
	humque[tail].x = 0; 
	for (int i = 1; i < m-1; i++){                           //��m-1��Ԫ�ظ���ֵ������������ 
		while (tail > head && nums[i] <= humque[tail].data) tail--;  //���㵥���� 
		humque[++tail].data = nums[i]; 
		humque[tail].x = i;
	}
	for (int i = m-1; i < nums.size() ; i++){
		while (tail >= head && nums[i] <=humque[tail].data) tail--;
		//cout << tail << endl;
		humque[++tail].data = nums[i];
		humque[tail].x = i;
		while (humque[head].x < i-m+1) head++;        //���������䷶Χ��Ԫ���޳� 
		min[i-m+1] = humque[head].data;             // ��������ͷԪ�ؼ�Ϊ��Сֵ 

	}
}
//ͬ�� 
void getMax(vector<int> &max, vector<int> &nums, int m){
	int head = 0, tail = 0;
	humque[tail].data = nums[0]; 
	humque[tail].x = 0; 
	for (int i = 1; i < m-1; i++){
		while (tail > head && nums[i] >= humque[tail].data) tail--;
		humque[++tail].data  = nums[i];
		humque[tail].x = i;
	}
	for (int i = m-1; i < nums.size(); i++){
		while (tail >= head && nums[i] >= humque[tail].data ) tail--;
		humque[++tail].data = nums[i];
		humque[tail].x = i;
		while (humque[head].x < i-m+1) head++;
		max[i-m+1] = humque[head].data ;
	}
}


int main(){
	vector<int> max(7);
	vector<int> min(7);
	vector<int> nums;
	for (int i = 0; i < 3; i++)
		nums.push_back(i+3);
	nums.push_back(-1);
	nums.push_back(7);
	nums.push_back(-5);
	nums.push_back(4);
	getMin (min, nums, 3);
	for (int i = 0; i <= min.size()-3; i++){
		cout << min[i] <<" " ;
	}
	return 0;
}
