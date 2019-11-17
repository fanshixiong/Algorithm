#include <iostream>
#include <vector>
using namespace std;

long long catalan (int n){
	if (n == 1 || n == 2)
		return 1;
	long long res = 0;
	for (int i = 1; i <= n-1; i++)
		res += catalan(i) * catalan(n-i);
	return res;
}  
//   nums[i][j]存储第i个卡特兰数的第j位， len[i]存储第i个卡特兰数的位数 
void catalanBigInteger (vector<int> &len, vector<vector<int> > &nums){
		int lenl, carry, i, j, tmp; // i 为第i个卡特兰数，  j为第i个卡特兰数的第j个数字 ， carry为进位，  tmp临时存储值 
		nums[1][0] = len[1] = 1;
		nums[0][0] = len[0] = 1;
		lenl = 1;
		for(int i = 2; i <= 10000; i++){
			for (int j = 0; j < lenl; j++)
				nums[i][j] = nums[i-1][j]*(4*i-2);
			carry = 0;
			for (int j = 0; j < lenl; j++){
				tmp = nums[i][j] + carry;
				nums[i][j] = tmp % 10;
				carry = tmp / 10;
			}
			while (carry){ 	
				nums[i][lenl++] = carry % 10;
				carry /= 10;
			}
			for (int j = lenl-1; j >= 0; j--){
				tmp = carry * 10 + nums[i][j];
				nums[i][j] = tmp / (i+1);
				carry = tmp % (i+1);
			}
			while (!nums[i][lenl-1])
				lenl--;
			len[i] = lenl;
		}
}
int main (){
	vector<int> len (10001);
	vector<vector<int> > nums(10001, vector<int> (10001));
	catalanBigInteger (len, nums);
	int n;
	cin >> n;
	int i = len[n]-1;
	while (i >= 0){
		cout << nums[n][i--];
	}
	cout <<endl;
/*	int b;
	cin >> b;
	cout << catalan (b) <<endl;
*/	
	return 0;
}
